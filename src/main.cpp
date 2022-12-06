#include <iostream>
#include "scene.h"
#include "scenes/collider_test1_scene.h"
#include "scenes/sphere_scene.h"
#include "rendererGL/camera.h"


int main(int argc, char** argv) {

    Demo::SphereScene scene(640, 480);
    scene.run();
    RendererGL::Camera::get_instance()->save(scene.title);
    return 0;
}
