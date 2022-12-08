#ifndef WINDOW_H
#define WINDOW_H

#include <abstraction/Xlibinterface.h>
#include <base/memory/MemoryPool.h>

#include <application/keys.h>

namespace CEGUI {
    namespace APP {

		typedef void* plhandle;

    struct Framebuffer {
      int* frame;
      unsigned int width, height, bytedepth;
    };

		struct ppblock { // pixel proccess block, 8 bytes wide, no need to change for 32 bit systems
			char data[8];
		};

		struct Pixel2b {
			char data[2];
		};

		struct Pixel3b {
			char data[3];
		};
		
		struct Pixel4b {
			char data[4];
		};
		
		Framebuffer XVideoBuffer[2];
			
    CEGUI_INIT(unsigned int width, unsigned int height);
		CEGUI_CLOSE();

		void SwapActiveBuffer();

		void HandleEvents();

		XErrorEvent GetError();
            
    void QueryKeys();
    bool GetKeyPressed(int key);

		
		Pixel4b GetPalleteColor4b(plhandle, char);
		Pixel4b GetPalleteColor3b(plhandle, char);
		Pixel4b GetpalleteColor2b(plhandle, char);
		

    //Atom* SendAtom(char* atomname, Bool only_if_exists); me angy. fix.

    void Update(); // draws framebuffer

		void QueryKeys();
          
    };
  };
};



#endif