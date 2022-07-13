#ifndef BOX_COMPONENT_H
#define BOX_COMPONENT_H

#include "component.h"
#include "physics/aabb.h"


namespace RendererGL {
    struct Shape;
}

namespace Physics {

    struct BoxComponent : public Component {
        BoxComponent(RendererGL::Shape* shape);

        void render();
        void update();

        AABB aabb;

    };
}

#endif
