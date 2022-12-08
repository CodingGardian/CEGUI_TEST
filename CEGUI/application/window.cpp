#include <application/window.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace CEGUI::APP;

Window x_win;
XSetWindowAttributes x_xswa;
Colormap x_cmap;
XVisualInfo* x_visinfo;
Display* x_dpy;
Screen* x_screen;
GC x_gc;
XGCValues x_gcval;
int x_scrnum;

XImage* x_framebuffer[2];
int x_width, x_height, x_total; // width, height, total size of framebuffer

int x_byteDepth;

char x_keyQuery[32];
char x_keyMap[64];

bool x_defaultcolor;

bool configure_notify;

bool CEGUI_initalized = false;

enum xfuncdesc {
	Xfunc_CreateWindow=0,
	Xfunc_OpenDisplay,
	Xfunc_CreateGC,
	Xfunc_MapWindow,
	Xfunc_CreateColormap,
	Xfunc_AllocColorCells
}

struct xcontext {
	XErrorEvent e;
	xfuncdesc fdesc;
};

xcontext x_context;

unsigned long x_redmask, x_greenmask, x_bluemask
unsinged int x_rshift, x_gshift, x_bshift;

int activebuffer=0;

#define CHECK_WIN 0x01
#define CHECK_FATAIL 0x01 << 1

Pixel2b x_colorto2byte[256];
Pixel3b x_colorto3byte[256];
Pixel4b x_colorto4bytes[256];


// TODO: Create a colormap that should be able to handle many different bit depths for the screen

// I'm pulling my hair out trying to find if X11 erros are called imediatley upon fail or later through asynchronous tomfoolery.
// For now we'll stick with the error handler being called immediatley on fail b/c the documnetation seems to suggest that :\
int HandleErrors(Display* dpy, XErrorEvent* err);

Display* xwrapOpenDisplay(char* displayname);

Window xwrapCreateWindow(Display* dpy, Window root, int x, int y, int width, 
												 int height, int borderwidth, int depth, unsidned int Class, Visaul visual, 
												 unsigned long valuemask, XSetWindowAttributes* attributes);

GC* xwrapCreateGC(Display* dpy, Drawable d, unsigned long valuemask, XGCValues* values);

void xwrapMapWindow(Display* dpy, Window win);

Colormap xwrapCreateColormap(Display* dpy, Window win, Visual* visual, int alloc);


void AllocateColorPallete(char* p); // 256 different colors

// not used if palleted are not used
void InitCTable16b(char* pallete) {
	// todo: implement!!!!
}

void InitCTable24b(char* pallete) {
	// todo: implement!!!!
}

void InitCTable32b(char* pallete) {
	// todo: implement!!!!
}

// color palletes are optinal
// TODO: Error checking using x_context
int CEGUI::APP::CEGUI_INIT(unsigned int width, unsigned int height, char* pallete, int bytedepth) {
	x_width = width;
	x_height = height;
	x_lastError = 0;
	CEGUI_initialized = true;
	
  // display and visual type
  x_dpy = xwrapOpenDisplay(0);
	if (!x_dpy) {Error("FAILED TO CREATE DISPLAY");}
    
  x_screen = XDefaultScreenOfDisplay(x_dpy);
  x_scrnum = XDefaultScreen(x_dpy);
	XSetErrorHandler(HandleErrors);
	
	
  XVisualInfo* tempvis;
  tempvis.c_class = PsudeoColor;
  tempvis.screen = x_scrnum;
  int num;
  x_visinfo = XGetVisualInfo(x_dpy, VisualClassMask|VisualScreenMask, &tempvis, &num);
	  if (!x_visinfo)  Error("XGetVisualInfo returned 0");
	for (int i=0; i<num; i++) {
		if (tempvis->depth == x_bytedepth*4) {break;}
		if (i = num-1 && x_bytedepth != -1) {Error("No visual info with requested byte depth!");}
		tempvis += 1;
	}

  // first allocate temporary colormap
	x_cmap = xwrapCreateColormap(x_dpy, RootWindow(x_dpy, x_scrnum), x_visinfo->visual, AllocNone);
    
  x_xswa.colormap = m_cmap;
  x_xswa.background_pixel = 0;
  x_xswa.border_pixel = 0;
  x_xswa.event_mask = ExposureMask | KeyPressMask | StructureNotifyMask;

	XSync(x_dpy, True);

	x_byteDepth = x_visinfo->depth / 8;
	x_redmask = x_visinfo->red_mask;
	x_greenmask = x_visinfo->green_mask;
	x_bluemask = x_visinfo->blue_mask;

	int align = 0;
	// todo: check byte depth stuff
	switch(x_byteDepth) {
		case 4:
			// alpha channel that will not be used :\, take advantage of this for byte allignmnet!
			// process two pixels at a time
			if (x_width % 2) {
				align = 1; 
				Warning("Byte depth causes misalignment, padding screen width!");
				printf("prev framebuffer width %i -> new framebuffer width %i", x_width, x_width+align);
			}
			if (pallete != nullptr) {InitCTable32b(pallete);}
			break;
		case 3:
			// complicated place... not good for byte allignemnt.
			// some extra work changing width to make alligned
			// --split into chars, process 2 + 2/3 of a pixel at a time... this will be a nightmare to implement-- <- don't like this, maybe just ignore alignment?
			/*if (x_width % 8 != 0) {
				align = 8 - (x_width%8);
				Warning("Byte depth causes misalignment, padding screen width!");
				printf("prev framebuffer width %i -> new framebuffer width %i", x_width, x_width+align);
			}*/

			if (pallete != nullptr) {InitCTable24b(pallete);}
			break;
		case 2:
			// another case of easy alignment
			// process 4 pixels at a time
			if (x_width % 4 != 0) {
				align = 4 - (x_width % 4);
				Warning("Byte depth causeses misalignment, padding screen width!");
				printf("prev framebuffer width %i -> new framebuffer width %i", x_width, x_width+align);
			}

			if (pallete != nullptr) {InitCTable16b(pallete);}
			
			break;
		case 1:
			// use colormaps, maximum speed
			// process 8 pixels at a time
			if (x_width % 8 != 0) {
				align = 8 - (x_width%8);
				Warning("Byte depth causes misalignment, padding screen width!");
				printf("prev framebuffer width %i -> new framebuffer width %i", x_width, x_width+align);
			}
			if (pallete == nullptr) {Error("Null pallete passed to CEGUI when x window byte depth is 1!");}
			AllocateColorPallete(pallete);
			break;
		default:
			Error("Unexpected byte depth!");
	}
	x_width += align;
	
  // window
  x_win = xwrapCreateWindow(x_dpy, XDefaultRootWindow(x_dpy), 100, 100, x_width, x_height, 0, 
                        x_visinfo->depth, InputOutput, x_visinfo->visual, CWBackPixel | CWColormap | 
												CWBorderPixel, &x_xswa);
	
	XFreeColormap(m_dpy, m_cmap);

	if (x_bytedepth == 1) {
		x_cmap = xwrapCreateColormap(m_dpy, XRootWindow(m_dpy, m_scrnum), x_visinfo->visual, AllocAll);
		XSetWindowColormap(m_dpy, m_win, x_cmap);
	}
	
  XSelectInput(x_dpy, x_win, ExposureMask | KeyPressMask | StructureNotifyMask);

  // Graphics Content
  x_gcval.graphics_exposures = 0;
  x_gc = xwrapCreateGC(x_dpy, x_win, GCGraphicsExposures, &x_gcval);

    // Framebuffer (XImage with more steps)
	unsigned char* FrameBuffer1 = malloc(width * height * x_bytedepth);
	unsigned char* FrameBuffer2 = malloc(width * height * x_bytedepth);

  for (int i=0; i<x_width*x_height*x_bytedepth; i++) {
    FrameBuffer1 + i = 0;
		FrameBuffer2 + i = 0; 
  }

  x_framebuffer[0] = XCreateImage(m_dpy, m_visinfo->visual, m_visinfo->depth, ZPixmap, 0, 
                               	  (char*)Framebuffer1, m_width, m_height, 32, 0);

	x_framebuffer[1] = XCreateImage(m_dpy, m_visinfo->visual, m_visinfo->depth, ZPixmap, 0, 
                               	  (char*)Framebuffer2, m_width, m_height, 32, 0);
	
  if (!x_framebuff) exit(-1);

	XVideoBuffer[0].memory = FrameBuffer1;
	XVideoBuffer[0].width = width;
	XVideoBuffer[0].height = height;
	XVideoBuffer[0].bytedepth = x_bytedepth;
	
	XVideoBuffer[1].memory = FrameBuffer2;
	XVideoBuffer[1].width = width;
	XVideoBuffer[1].height = height;
	XVideoBuffer[1].bytedepth = x_bytedepth;
    
  usleep(1000);

  XMapWindow(m_dpy, m_win);

  XSync(m_dpy, True);
	
	MapKeys();
	
	HandleEvents();
  // finally done :)
}

void AllocateColorPallete(char* pallete) {
	XColor colors[256];

	for (int i=0; i<256; i++) {
		colors[i].flags = DoRed | DoGreen | DoBlue;
		colors[i].red = *pallete;
		colors[i].green = *(pallete+1);
		colors[i].blue = *(pallete+2);

		pallete += 3;
	}

	XStoreColors(x_dpy, x_cmap, colors, 256);
}

int ErrorHandler(Display* dpy, XErrorEvent* err) {
	switch(err->type) {
		case BadWindow:
			Warning("BadWindow error generated by Xlib");
			x_context.e = *err;
			break;
		//case 
	}
}


Display* xwrapOpenDisplay(char* displayname) {
	x_context.fdesc = Xfunc_OpenDisplay;
	return XOpenDisplay(displayname);
}

Window xwrapCreateWindow(Display* dpy, Window root, int x, int y, int width, 
																int height, int borderwidth, int depth, unsidned int Class,
																Visaul visual, unsigned long valuemask, XSetWindowAttributes* attributes) 
{
	x_context.fdesc = Xfunc_CreateWindow;
	return XCreateWindow(dpy, root, x, y, width, height, borderwidth, depth, Class, visual, valuemask, attributes);
}

GC* xwrapCreateGC(Display* dpy, Drawable d, unsigned long valuemask, XGCValues* values) {
	x_context.fdesc = Xfunc_CreateGC;
	return XCreateGC(dpy, d, valuemask, values);
}

void xwrapMapWindow(Display* dpy, Window win) {
	x_context.fdesc = Xfunc_MapWindow;
	XMapWindow(dpy, d, valuemask, values);
}

Colormap xwrapCreateColormap(Display* dpy, Window win, Visual* visual, int alloc) {
	x_context.fdesc = Xfunc_CreateColormap
	return XCreateColormap(dpy, win, visual, alloc);
}

void MapKeys() {
	m_keyMap[CEK_UP] = XKeysymToKeycode(m_dpy, XK_Up);
	m_keyMap[CEK_DOWN] = XKeysymToKeycode(m_dpy, XK_Down);
	m_keyMap[CEK_LEFT] = XKeysymToKeycode(m_dpy, XK_Left);
	m_keyMap[CEK_RIGHT] = XKeysymToKeycode(m_dpy, XK_Right);

	for (int i=4; i<100; i++) {
		m_keyMap[i] = ' ';
	}
	
}

void Resize(int width, int height) {
    if (m_width == width && m_height == height) {return;}
    
    m_width = width;
    m_height = height;

    m_framebuff.m_width = width;
    m_framebuff.m_height = height;

    XDestroyImage(m_Xframebuff); // frees the memory pointed by the framebuffer too

    m_framebuff.m_memory = (int*)malloc(m_height*m_width*4);
    
    for (int i=0; i<m_width*m_height; i++) {
        m_framebuff.m_memory[i] = 0xFF00FFFF;
    }

    x_framebuffer[0] = XCreateImage(m_dpy, m_visinfo->visual, m_visinfo->depth, ZPixmap, 0, 
                               	  (char*)Framebuffer1, m_width, m_height, 32, 0);

		x_framebuffer[1] = XCreateImage(m_dpy, m_visinfo->visual, m_visinfo->depth, ZPixmap, 0, 
                               	  (char*)Framebuffer2, m_width, m_height, 32, 0);
	
    if (!m_Xframebuff) exit(-1);
}

void CEGUI::APP::Update() {
    XPutImage(m_dpy, m_win, m_gc, m_Xframebuff[activebuffer], 0, 0, 0, 0, m_width, m_height);
}


void CEGUI::APP::QueryKeys() {
    XQueryKeymap(m_dpy, m_keyQuery);
}

void CEGUI::APP::HandleEvents() {
	if (XPending(x_dpy)) {
		XEvent e;
		while (XNextEvent(x_dpy, e)) {
			switch(e.type) {
				case ConfigureNotify:
					resize(e.width, e.height);
					break;
				case MotionNotify:
					// move pointer to center of screen
					break;
				default:
					break;
			}

			
		}
	}
}

bool CEGUI::APP::GetKeyPressed(int key) {
    char keycode = m_keyMap[key];

    if ( ( (m_keyQuery[keycode/8]) & (0x1 << keycode%8) )) {
        return true;
    }

    return false;
}

void CEGUI::APP::CEGUI_CLOSE() {
    XFreeGC(x_dpy, x_gc);
    if (!defaultcolor) XFreeColormap(m_dpy, m_cmap);
    XFree(m_visinfo);
    XDestroyImage(m_Xframebuff);
    XDestroyWindow(m_dpy, m_win);
    XFree(m_screen);
    XFree(m_dpy);

    XSync(m_dpy, True);
}

