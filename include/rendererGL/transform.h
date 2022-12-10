#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include "vector3.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

namespace RendererGL {

    class Transform {
        public:
            Transform();
            virtual ~Transform();

            glm::mat4 get_model() const { return model; }
            Vector3 get_position() const { return position; }
            Vector3 get_scale() const { return scale; }

            void set_position(const Vector3& position);
            void set_rotation(const Vector3& rotation);
            void set_rotation(const glm::quat orientation);
            void set_scale(const Vector3& scale);

            void update();

        private:
            glm::mat4 model;

            Vector3 position;
            Vector3 scale;
            glm::quat orientation;

    };


}

#endif
