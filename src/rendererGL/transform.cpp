#include "rendererGL/transform.h"
#include <glm/gtc/matrix_transform.hpp>

namespace RendererGL {

    Transform::Transform() {
        model = glm::mat4(1.0f);
    }

    Transform::~Transform(){

    }

    void Transform::set_position(const Vector3& position) {
        this->position = position;
        model = glm::translate(model, glm::vec3(position.x, position.y, position.z));
    }


    void Transform::set_rotation(const Vector3& rotation) {
        // tobe implmeneted
    }


    void Transform::set_scale(const Vector3& scale) {
        // tobe implemented
    }
}