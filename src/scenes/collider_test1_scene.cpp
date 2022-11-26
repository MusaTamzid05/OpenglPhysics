#include "scenes/collider_test1_scene.h"
#include "physics/mover_component.h"
#include "physics/box_component.h"
#include "rendererGL/cube.h"
#include <iostream>

namespace Demo {

    ColliderTest1Scene::ColliderTest1Scene( 
            const std::string& title,
            int width,
            int height 
            ):Scene(title, width, height) {

        std::cout << "Scene initialize.\n";

        objs.push_back(new RendererGL::Cube());
        objs[0]->set_color(Vector3(0.0f, 0.5f, 0.0f));
        objs[0]->transform.set_position(Vector3(0.0f, 0.0f, 0.0f));
        objs[0]->m_components.push_back(new Physics::MoveComponent(objs[0]));
        objs[0]->m_components.push_back(new Physics::BoxComponent(objs[0]));

        RendererGL::Cube* plane = new RendererGL::Cube();
        plane->transform.set_position(Vector3(0.0f, -10.0f, 0.0f));
        plane->transform.set_scale(Vector3(20.0f, 1.0f, 20.0f));
        plane->set_color(Vector3(0.7f, 0.5f, 0.3f));
        plane->m_components.push_back(new Physics::BoxComponent(plane));

        objs.push_back(plane);

    }

}
