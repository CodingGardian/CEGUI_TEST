#include <application/window.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace CEGUI::APP;

WindowBase::WindowBase(unsigned int width, unsigned int height) : m_width(width), m_height(height) {
    // display and visual type
    m_dpy = XOpenDisplay(0);
    
    m_screen = XDefaultScreenOfDisplay(m_dpy);
    m_scrnum = XDefaultScreen(m_dpy);

    XVisualInfo tempvis;
    tempvis.c_class = TrueColor;
    tempvis.screen = m_scrnum;
    int num;
    m_visinfo = XGetVisualInfo(m_dpy, VisualClassMask|VisualScreenMask, &tempvis, &num);

    if (!m_visinfo)  exit(-1);

    // color
    if (m_visinfo->visual != DefaultVisual(m_dpy, m_scrnum)) {
        m_cmap = XCreateColormap(m_dpy, RootWindow(m_dpy, m_scrnum), m_visinfo->visual, AllocNone);
    }
    else {m_cmap = XDefaultColormapOfScreen(m_screen);}
    
    m_xswa.colormap = m_cmap;
    m_xswa.background_pixel = 0;
    m_xswa.border_pixel = 0;
    m_xswa.event_mask = ExposureMask | KeyPressMask | StructureNotifyMask;

    XSync(m_dpy, True);
    
    // window
    m_win = XCreateWindow(m_dpy, XDefaultRootWindow(m_dpy), 100, 100, m_width, m_height, 0, 
                        m_visinfo->depth, InputOutput, m_visinfo->visual, CWBackPixel | CWColormap | CWBorderPixel, 
                        &m_xswa);
    
    XSelectInput(m_dpy, m_win, ExposureMask | KeyPressMask | StructureNotifyMask);

    // Graphics Content
    m_gcval.graphics_exposures = 0;
    m_gc = XCreateGC(m_dpy, m_win, GCGraphicsExposures, &m_gcval);

    // Framebuffer (XImage with more steps)
    m_framebuff.m_memory = (int*)malloc(4*m_width*m_height);

    for (int i=0; i<m_width*m_height; i++) {
        m_framebuff.m_memory[i] = 0xFF00FFFF;
    }

    m_Xframebuff = XCreateImage(m_dpy, m_visinfo->visual, m_visinfo->depth, ZPixmap, 0, 
                               (char*)m_framebuff.m_memory, m_width, m_height, 32, 0);

    if (!m_Xframebuff) exit(-1);
    
    usleep(1000);

    XMapWindow(m_dpy, m_win);

    XSync(m_dpy, True);

    // finally done :)

}

Framebuffer& WindowBase::GetFramebuff() {
    return m_framebuff;
}

XImage* WindowBase::GetXBuff() {
    return m_Xframebuff;
}

void WindowBase::resize(int width, int height) {
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

    m_Xframebuff = XCreateImage(m_dpy,m_visinfo->visual,m_visinfo->depth, ZPixmap, 0, 
                                (char*)m_framebuff.m_memory, m_width, m_height, 32, 0);
    
    if (!m_Xframebuff) exit(-1);
}

void WindowBase::Update() {
    XPutImage(m_dpy, m_win, m_gc, m_Xframebuff, 0, 0, 0, 0, m_width, m_height);
}

int WindowBase::PendingEvents() {
    return XPending(m_dpy);
}

void WindowBase::QueryKeys() {
    XQueryKeymap(m_dpy, m_keyQuery);
}

void WindowBase::GetEvent(XEvent* e) {
    XNextEvent(m_dpy, e);
}

bool WindowBase::GetKeyPressed(int XKey) {
    char keycode = XKeysymToKeycode(m_dpy, XKey);

    if ( ( (m_keyQuery[keycode/8]) & (0x1 << keycode%8) )) {
        return true;
    }

    return false;
}

WindowBase::~WindowBase() {
    XFreeGC(m_dpy, m_gc);
    XFreeColormap(m_dpy, m_cmap);
    XFree(m_visinfo);
    XDestroyImage(m_Xframebuff);
    XDestroyWindow(m_dpy, m_win);
    XFree(m_screen);
    XFree(m_dpy);

    XSync(m_dpy, True);
}

