//#include <events/events.h>
// cd "/usercode/" && g++ -I /usercode/CEGUI/ main.cpp CEGUI/application/window.cpp CEGUI/application/application.cpp CEGUI/base/graphicsutil/impl.cpp -lX11 -o main && "/usercode/"main

// cd "/usercode/" && g++ -I /usercode/CEGUI/ main.cpp CEGUI/base/memory/ram.cpp CEGUI/base/memory/texture.cpp -o main && "/usercode/"main

// TODO:
    // Finish up basic minumum for application class
        // Key Presses (finished)
        // Framebuffer (finished)
    // Code graphics utility for drawing
        // b e e g rectangle (finished)
        // precomputed trigonometry <- no actually russian math and lots of pain (Thank the lord that Chebyshev exits) (눈_눈) SPEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEED (finished)
        // wut (do tan later) (finished)
        // bresenhams line drawing algorithm (finished)
        // use line algorithm for optimized poly drawing (finished)
        // memory managment stuff
        // file io
        // demo to replit
        // done by the 20th <---- I'm from the future, this does not happen :(

// aux_ <-- auxillary function
//
//


//#include <application/application.h>
//#include <base/graphicsutil/gutil.h>
#include <base/memory/texture.h>
#include <base/memory/ram.h>
#include <fstream>

#include <iostream>
#include <chrono>
#include <cmath>
#include <base/math.h>
#include <unistd.h>

using namespace std::chrono;
using namespace std;

/*float uval[] = {-0.9659258, -0.70710678, -0.258819, 0.258819, 0.70710678, 0.9659258};
float xval[] = {-0.9659258, -0.70710678, -0.258819, 0.258819, 0.70710678, 0.9659258};
float yval[] = {-0.768675, -0.6154797, -0.2532616, 0.25326136, 0.61547971, 0.7680675};


float T0func(float u) {
    return 1.0;
}

float T1func(float u) {
    return u;
}

float T2func(float u) {
    return 2*u*u - 1;
}

float T3func(float u) {
    return 4*u*u*u - 3*u;
}

float T4func(float u) {
    return 8*u*u*u*u-8*u*u+1;
}

float T5func(float u) {
    return 16*u*u*u*u*u - 20*u*u*u + 5*u;
}

typedef float(*Tfunc)(float);

Tfunc funcs[] = {T0func, T1func, T2func, T3func, T4func, T5func};

float Getc(int cval, int n) {
    float sum = 0.0;
    for (int i=0; i<n; i++) {
        sum += funcs[cval](uval[i]) * yval[i];
    }

    sum /= float(n);

    if (cval == 0) {return sum;}

    return sum * 2;
}

float catan(float x) {
    float x2 = x*x;

    return CEGUI::MATH::pi2*( 0.5274*x + -0.030213*(4*x2*x - 3*x) + 0.0034855*(16*x2*x2*x - 20*x2*x + 5*x) );
}

float catan2(float y, float x) {
    float temp = y/x;
    if (temp > 1.0 || temp < -1.0) {
        return CEGUI::MATH::pi2 - catan(1/temp);
    }

    return catan(temp);
}

float cacos(float x) {
    using namespace CEGUI::MATH;

    x = fabs(x); // cos(-x) = cos(x)
    x = (x - twopi*std::floor(x/twopi));

    if (pi2 < x && x < pi3) {
        x = std::fabs(pi - x)/pi;

        float x2 = x*x;
        return -(0.472 - 0.4994*(8*x2 - 1) + 0.027985*(128*x2*x2 - 32*x2 + 1));
    }
    
    
    float x2 = x*x;
    return 0.472 - 0.4994*(8*x2 - 1) + 0.027985*(128*x2*x2 - 32*x2 + 1);
}*/

int main() {
    using namespace CEGUI;

    /*APP::Application app(600, 400);

    Atom wmDeleteMessage = XInternAtom(app.w.m_dpy, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(app.w.m_dpy, app.w.m_win, &wmDeleteMessage, 1);

    bool running = true;
    
    while(running) {
        app.START_FRAME(); // preps keys 
        while( app.w.PendingEvents() ) {
            XEvent e;
            app.w.GetEvent(&e);
            switch(e.type) {
                case Expose:
                    // draw I guess...
                    std::cout << "Expose message" << std::endl;
                    break; 
                case ClientMessage:
                    std::cout << "ClientMessage" << std::endl;
                    if (e.xclient.data.l[0] == wmDeleteMessage)
                        running = false;
                    break;
                case ConfigureNotify:
                    {
                    std::cout << "Configure message" << std::endl;
                    XConfigureEvent ce = e.xconfigure;
                    
                    app.w.resize(ce.width, ce.height);
                    }
                    break;
                default:
                    break;
            }
        }

        //RENDERING::drawRect(app.w.GetFramebuff(), 0, 0, 100, 100);
        RENDERING::drawline(app.w.GetFramebuff(), 200, 300, 10, 10);
        app.END_FRAME(); // draws framebuffer to screen
    }*/

    // https://courses.cs.vt.edu/cs2604/spring03/binio.html
    /*std::fstream t;
    t.open("text.stuff", std::ios::out | std::ios::binary);

    int i=2,j=5;
    t.write((char*)&i, sizeof(int));
    t.write((char*)&j, sizeof(int));

    char ah='f';

    for (int i=0; i<10*4; i++) {
        t.write((char*)&ah, sizeof(char));
    }*/


    CEGUI::MEMORY::INIT_MEM();

    CEGUI::MEMORY::TEXTURE::INIT_TEXTURE(110, 100);
    CEGUI::MEMORY::TEXTURE::allocate("text.stuff");
    CEGUI::MEMORY::TEXTURE::allocate("aaaahhhhh.amogus");

    std::cout << "\n";
    CEGUI::MEMORY::TEXTURE::mt->doit();

    CEGUI::MEMORY::END();
}