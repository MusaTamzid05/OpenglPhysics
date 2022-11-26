#include <iostream>
#include "scene.h"
#include "scenes/collider_test1_scene.h"
#include "rendererGL/camera.h"

int main(int argc, char** argv) {

    Demo::ColliderTest1Scene scene("Display", 640, 480);
    scene.run();
    RendererGL::Camera::get_instance()->save();
    return 0;
}
