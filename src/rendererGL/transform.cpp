#include "rendererGL/transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

namespace RendererGL {


    Transform::Transform() {
    }

    Transform::~Transform(){

    }

    void Transform::set_position(const Vector3& position) {
        model = glm::mat4(1.0f);
        this->position = position;
        model = glm::translate(model, glm::vec3(position.x, position.y, position.z));
    }


    void Transform::set_rotation(const Vector3& rotation) {
    }

    void Transform::set_rotation(const glm::quat orientation) {
        model = glm::mat4_cast(orientation) * model;

    }
    void Transform::set_scale(const Vector3& scale) {
        this->scale = scale;
        model = glm::scale(
                model,
                glm::vec3(scale.x, scale.y, scale.z)
                );
    }





}
