#ifndef MOVER_COMPONENT_H
#define MOVER_COMPONENT_H

#include "component.h"
#include "vector3.h"

namespace RendererGL {
    struct Shape;
}

namespace Physics {
    struct  Shape;

    struct MoveComponent : public Component {
        MoveComponent(RendererGL::Shape* shape, bool gravity_flag = true, float mass = 30.0f);

        virtual void render();
        virtual void update();

        void apply_force(const Vector3& force);

        Vector3 position;
        Vector3 velocity;
        Vector3 acceleration;

        float mass;
        bool gravity_flag;


    };
}

#endif
