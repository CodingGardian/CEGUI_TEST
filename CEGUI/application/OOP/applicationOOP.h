#ifndef APPLICATION_H
#define APPLICATION_H

#include <application/window.h>

namespace CEGUI {
    namespace APP {
			typedef void (*HANDLE_EXPOSE_EVENT)(XEvent e);
			typedef void (*HANDLE_CONFIGURE_EVENT)(XEvent e);
			typedef void (*HANDLE_MISC_EVENT)(XEvent e);

			struct InitApplicationData {
				HANDLE_EXPOSE_EVENT expose_handle;
				HANDLE_CONFIGURE_EVENT configure_handle;
				HANDLE_MISC_EVENT misc_handle;
				// event handles
				
				int width, height;

				bool Threaded; // boolean to tell if threaded application
			};

			InitApplicationData GetDefaultApplicationData();

      class Application { 
      private:

      public:
          Application(InitApplicationData in);
          ~Application();

  	      WindowBase w;

          void START_FRAME();
          void END_FRAME();

					void HandleEvents();
            
        };
    };
};

#endif