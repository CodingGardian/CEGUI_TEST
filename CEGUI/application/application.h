#ifndef APPLICATION_H
#define APPLICATION_H

#include <application/window.h>

namespace CEGUI {
    namespace APP {
        class Application { 
        private:

        public:
            Application(int width, int height);
            ~Application();

            WindowBase w;

            void START_FRAME();
            void END_FRAME();
            
        };
    };
};

#endif