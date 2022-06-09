/*#include <events/events.h>
#include<abstraction/Xlibinterface.h>

using namespace CEGUI::EVENTS;



/*void EventSys::InitEvent() {
    if (!CEGUI::XINTERFACE::INTERFACE_INITIALIZED) {return;}
    // initialize keys using display
    KEY_W = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_w);
    KEY_A = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_a);
    KEY_S = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_s);
    KEY_D = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_d);
    KEY_SPACE = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_space);
    KEY_COMMA = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_comma);
    KEY_PERIOD = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_period);
    KEY_UP = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_Up);
    KEY_DOWN = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_Down);
    KEY_LEFT = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_Left);
    KEY_RIGHT = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_Right);

    KEY_ARR[0] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_w);
    KEY_ARR[1] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_a);
    KEY_ARR[2] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_s);
    KEY_ARR[3] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_d);
    KEY_ARR[4] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_space);
    KEY_ARR[5] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_comma);
    KEY_ARR[6] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_period);
    KEY_ARR[7] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_Up);
    KEY_ARR[8] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_Down);
    KEY_ARR[9] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_Left);
    KEY_ARR[10] = XKeysymToKeycode(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, XK_Right);

}*/


/*const std::unique_ptr<KeyEvent>& EventSys::KeyboardPoll() {
    char keys[32];

    XQueryKeymap(CEGUI::XINTERFACE::SCREENDRIVERINTERFACE::dpy, keys);
    
    

    for (int i=0; i<11; i++) {
        if (keys[KEY_ARR[i]/8] & (0x1 << (KEY_ARR[i]%8))) {
            
        }
    }

}*/