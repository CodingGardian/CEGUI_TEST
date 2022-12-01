
/************************* 
 * Remember to free memory using X functions
 * Avoid any function overhead (use wrappers ONLY when necesary, inline when wont make program chonk)
/*************************/
#ifndef XLIBINTERFACE_H
#define XLIBINTERFACE_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#define INIT_OK 0x80000000
#define NOT_TRUECOLOR 0x80000001 // was unable to initialize truecolor colormap on display

#define DISPLAY_ERROR 0x00000001
#define SCREEN_ERROR 0x00000002
#define XLIB_ERROR 0x00000003

#define UNKOWN 0

namespace CEGUI {
    namespace INTERFACE {
        //bool INTERFACE_INITIALIZED = false;
        int Init(); // get display, screen, initialize truecolor (or use something else if forced to)

        void initkeys();

        /*namespace SCREENDRIVERINTERFACE {

            // colormaps (allocating colormaps BAD)
            class SDIColorInfo {
            private:
                Colormap m_cmap;
            public:
                SDIColorInfo(bit depth, type, etc.);
                ~SDIColorInfo(); // clean up using Xlib freeing functions

                XColor GetColor(short r, short g, short b);
                
            };

            struct SDIFrameBuffer {
                XImage* img;
                int width, height, numbits;
                char* mem;
            };

            
        };*/


        
    };
};

#endif