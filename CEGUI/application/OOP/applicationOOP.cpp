#include<application/application.h>

using namespace CEGUI::APP;

Application::Application(int width, int height) : w(width, height) {

}

Application::~Application() {

}

void DEFAULT_EXPOSE_HANDLER(XEvent e) {
	
};

void DEFAULT_CONFIGURE_HANDLER(XEvent e) {
	
}


void Application::START_FRAME() {
    w.QueryKeys();
}

void Application::END_FRAME() {
    w.Update();
}