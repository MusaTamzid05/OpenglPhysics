#include "physics/aabb.h"
#include "rendererGL/transform.h"
#include <iostream>

namespace Physics {
    AABB::AABB(RendererGL::Transform* transform):transform(transform) {
        update_vectors();
    }

    void AABB::update_vectors() {
        Vector3 position = transform->get_position();
        Vector3 scale = transform->get_scale();
        min = Vector3(position.x - scale.x, position.y - scale.y, position.z - scale.z);
        max = Vector3(position.x + scale.x, position.y + scale.y, position.z + scale.z);

    }


    bool AABB::intersect(AABB& a, AABB& b) {

        // for this to work, a must be min small size vector.
        // This is not the case for aabb, but there is a
        // problem in my implementation, this is by far
        // the worst implemention ever but it will
        // do for now.
        if(a.min.magnitude() > b.min.magnitude()) {
            AABB temp = a;
            a = b;
            b = temp;
        }


        //std::cout << "a " << a.min.magnitude() << " " << a.max.magnitude() << "\n";
        //std::cout << "b " << b.min.magnitude() << " " << b.max.magnitude() << "\n";

        bool collision_x_min = a.min.x >= b.min.x  && a.min.x < b.max.x;
        bool collision_y_min = a.min.y >= b.min.y  && a.min.y < b.max.y;
        bool collision_z_min = a.min.z >= b.min.z  && a.min.z < b.max.z;

        if(collision_x_min && collision_y_min && collision_z_min)
            return true;


        bool collision_x_max = a.max.x >= b.min.x  && a.max.x < b.max.x;
        bool collision_y_max = a.max.y >= b.min.y  && a.max.y < b.max.y;
        bool collision_z_max = a.max.z >= b.min.z  && a.max.z < b.max.z;

        if(collision_x_max && collision_y_max && collision_z_max)
            return true;

        return false;


    }
}
