#include "physics/aabb.h"
#include "rendererGL/transform.h"

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


    bool AABB::intersect(const AABB& a, const AABB& b) {
        if((a.min.x > b.min.x) && (a.min.x < b.max.x))
            return true;

        if((a.min.y > b.min.y) && (a.min.y < b.max.y))
            return true;

        if((a.min.z > b.min.z) && (a.min.z < b.max.z))
            return true;


        if((a.max.x > b.min.x) && (a.max.x < b.max.x))
            return true;

        if((a.max.y > b.min.y) && (a.max.y < b.max.y))
            return true;

        if((a.max.z > b.min.z) && (a.max.z < b.max.z))
            return true;

        return false;
    }
}
