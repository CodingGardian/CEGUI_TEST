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

/* TODO:
*		Better Event handler
*		Error handlers too?
*		Some more functions (drawing characters & maybe pixmaps & bitmaps)
* 
*		Finish variable array (eventually)
* 	Demo to Replit (eventually)
*
*/

// aux_ <-- auxillary function
//
//


// What I want this to look like:
// 	while loop
// 	start frame
// 	do stuff (if key is pressed, draw directly to frame buffer)
//  	-> predefined characters
// 	end frame

// need to handle atoms & events


#include <application/application.h>
#include <base/graphicsutil/gutil.h>
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

    /*Atom wmDeleteMessage = XInternAtom(app.w.m_dpy, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(app.w.m_dpy, app.w.m_win, &wmDeleteMessage, 1);*/
		APP::CEGUI_INIT(100, 200, nullptr, 4);
    bool running = true;
    
    while(running) {
      APP::HandleEvents();
			if (APP::GetKeyPressed(CEK_UP)) {
				std::cout << "Key UP pressed!\n";
			}
    }

    // https://courses.cs.vt.edu/cs2604/spring03/binio.html

}