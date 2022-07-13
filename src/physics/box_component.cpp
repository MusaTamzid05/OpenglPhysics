#include "physics/box_component.h"
#include "rendererGL/game_object.h"
#include <iostream>

namespace Physics {
    BoxComponent::BoxComponent(RendererGL::GameObject* obj):
        Component("box_component", obj),aabb(&obj->transform) {
            aabb.update_vectors();
    }


    void BoxComponent::render() {

    }

    void BoxComponent::update() {
        aabb.update_vectors();
    }


}


