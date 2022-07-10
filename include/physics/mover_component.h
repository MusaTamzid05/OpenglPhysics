#ifndef MOVER_COMPONENT_H
#define MOVER_COMPONENT_H

#include "component.h"

namespace Physics {
    struct MoveComponent : public Component {
        MoveComponent();

        virtual void render();
        virtual void update();
    };
}

#endif
