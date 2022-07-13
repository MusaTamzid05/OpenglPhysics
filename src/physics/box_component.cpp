#include "physics/box_component.h"
#include "rendererGL/shape.h"

namespace Physics {
    BoxComponent::BoxComponent(RendererGL::Shape* shape):
        Component("box_component", shape),aabb(&shape->transform) {
            aabb.update_vectors();
    }


    void BoxComponent::render() {

    }

    void BoxComponent::update() {
        aabb.update_vectors();
    }


}


