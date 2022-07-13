#ifndef AABB_H
#define AABB_H

#include "vector3.h"

namespace RendererGL {
    class Transform;
};

namespace Physics {
    struct AABB {

        AABB(RendererGL::Transform* transform);
        void update_vectors();
        static bool intersect(AABB& a, AABB& b);

        Vector3 min;
        Vector3 max;

        RendererGL::Transform* transform;
    };
}

#endif
