#include "physics/collider_system.h"
#include "rendererGL/shape.h"

namespace Physics {
    ColliderSystem* ColliderSystem::instance = nullptr;

    ColliderSystem::ColliderSystem() {


    }

    ColliderSystem* ColliderSystem::get_instance() {
        if(instance == nullptr)
            return instance;
    }

    void ColliderSystem::update() {
        if(shapes.size() < 2)
            return;

        for(unsigned int i = 0; i < shapes.size(); i += 1) {
            for(unsigned int j = 0; j < shapes.size(); j += 1) {
                if(i == j)
                    continue;

                if(collided(shapes[i], shapes[j])) {

                }



            }

        }
    }


    bool ColliderSystem::collided(const RendererGL::Shape* shape1, const RendererGL::Shape* shape2) const {
        return false;
    }
}
