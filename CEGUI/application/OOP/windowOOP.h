#ifndef WINDOW_H
#define WINDOW_H

#include <abstraction/Xlibinterface.h>
#include <base/memory/MemoryPool.h>

#include <application/keys.h>

namespace CEGUI {
    namespace APP {
        struct Framebuffer {
            int* m_memory;
            unsigned int m_width, m_height;
        };
			
        class WindowBase {
  			private:
            Window m_win;
            XSetWindowAttributes m_xswa;
            Colormap m_cmap;
            XVisualInfo* m_visinfo;
            Display* m_dpy;
            Screen* m_screen;
            GC m_gc;
            XGCValues m_gcval;
            int m_scrnum;

            XImage* m_Xframebuff;
            int* m_memory;
            int m_width, m_height, m_total; // width, height, total size of framebuffer
            Framebuffer m_framebuff;
            
            char m_keyQuery[32];
						char m_keyMap[64];

						bool m_defaultcolor;

						void MapKeys();
				public:
            WindowBase(unsigned int width, unsigned int height);
            ~WindowBase();

            Framebuffer& GetFramebuff(); // gets the framebuffer
            XImage* GetXBuff(); // gets the ximage structure
            void resize(int width, int height);

            int PendingEvents(); // returns number of events in queue
            void GetEvent(XEvent* e);
            
            void QueryKeys();
            bool GetKeyPressed(int key);

            //Atom* SendAtom(char* atomname, Bool only_if_exists); me angy. fix.

            void Update(); // draws framebuffer
          
        };
    };
};



#endif