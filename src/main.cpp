#include <iostream>
#include "display.h"
#include "rendererGL/camera.h"

int main(int argc, char** argv) {

    Engine::Display display("Display", 640, 480);
    display.run();
    RendererGL::Camera::get_instance()->save();
    return 0;
}
