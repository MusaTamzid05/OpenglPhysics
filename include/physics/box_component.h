#ifndef BOX_COMPONENT_H
#define BOX_COMPONENT_H

#include "component.h"
#include "physics/aabb.h"


namespace RendererGL {
    struct GameObject;
}

namespace Physics {

    struct BoxComponent : public Component {
        BoxComponent(RendererGL::GameObject* obj);

        void render();
        void update();

        AABB aabb;

    };
}

#endif
