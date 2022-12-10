#include "rendererGL/transform.h"

namespace RendererGL {


    Transform::Transform() {
        scale = Vector3(1.0f, 1.0f, 1.0f);
        orientation = glm::quat(1.0f, 0.0f,0.0f,0.0f);

    }

    Transform::~Transform(){

    }

    void Transform::set_position(const Vector3& position) {
        this->position = position;
        model = glm::translate(model, glm::vec3(position.x, position.y, position.z));
    }


    void Transform::set_rotation(const Vector3& rotation) {
    }

    void Transform::set_rotation(const glm::quat orientation) {
        this->orientation = orientation;

    }
    void Transform::set_scale(const Vector3& scale) {
        this->scale = scale;
    }




    void Transform::update() {
        model = glm::translate(glm::mat4(1.0), glm::vec3(position.x, position.y, position.z)) * glm::mat4_cast(orientation) * glm::scale(glm::mat4(1.0f), glm::vec3(scale.x, scale.y, scale.z));

    }



}
