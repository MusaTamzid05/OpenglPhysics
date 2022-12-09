#include "scenes/bullet_physics_demo_scene.h"
#include "rendererGL/plane.h"
#include <iostream>

namespace Demo {

    BulletPhysicsDemoScecne::BulletPhysicsDemoScecne( 
            int width,
            int height 
            ):Scene("scenes/bullet_physics_demo_scene",  width, height) {

        std::cout << "Scene initialize.\n";

        objs.push_back(new RendererGL::Plane());
        objs[0]->set_color(Vector3(0.0f, 0.5f, 0.0f));

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
