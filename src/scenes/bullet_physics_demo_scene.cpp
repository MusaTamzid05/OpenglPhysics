#include "scenes/bullet_physics_demo_scene.h"
#include "rendererGL/plane.h"
#include "rendererGL/cube.h"
#include <iostream>

namespace Demo {

    BulletPhysicsDemoScecne::BulletPhysicsDemoScecne( 
            int width,
            int height 
            ):Scene("scenes/bullet_physics_demo_scene",  width, height) {

        std::cout << "Scene initialize.\n";

        RendererGL::Plane* plane =  new RendererGL::Plane();
        plane->set_color(Vector3(0.0f, 0.5f, 0.0f));


        RendererGL::Cube* cube = new RendererGL::Cube(this);
        cube->transform.set_position(Vector3(0.0f, 5.0f, 0.0));
        cube->set_color(Vector3(0.7f, 0.3f, 0.0f));

        objs.push_back(cube);
        objs.push_back(plane);

        //objs[1]->set_color(Vector3(0.0f, 0.5f, 0.0f));

        /*
        RendererGL::Cube* plane = new RendererGL::Cube();
        plane->transform.set_position(Vector3(0.0f, -10.0f, 0.0f));
        plane->transform.set_scale(Vector3(20.0f, 1.0f, 20.0f));
        plane->set_color(Vector3(0.7f, 0.5f, 0.3f));
        plane->m_components.push_back(new Physics::BoxComponent(plane));

        objs.push_back(plane);
        */

    }

}
