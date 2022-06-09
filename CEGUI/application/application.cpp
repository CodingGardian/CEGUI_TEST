#include<application/application.h>

using namespace CEGUI::APP;

Application::Application(int width, int height) : w(width, height) {

}

Application::~Application() {

}


void Application::START_FRAME() {
    w.QueryKeys();
}

void Application::END_FRAME() {
    w.Update();
}