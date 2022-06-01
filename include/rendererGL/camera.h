#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"
#include <glm/glm.hpp>

namespace RendererGL {
    enum CameraMovement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    class Camera {

        // far = - x
        // close = +x
        // up  = +y
        // down = -y
        // left = +z
        // right = -z
        public:
            virtual ~Camera() {}
            glm::mat4 projection;
            static void initialize(const Vector3& position, int width, int height);
            static Camera* get_instance();
            void process_keyboard(CameraMovement direction);
            glm::mat4 get_view_matrix();
            static void process_mouse_scroll(float offset);

            void update();

        private:

            Camera(const Vector3& position, int width, int height);

            Vector3 position;
            glm::vec3 front;
            glm::vec3 up;
            glm::vec3 right;
            glm::vec3 world_up;

            void update_camera_vector();
            void init_projection();


            void process_mouse_movement(float xoffset, float yoffset, bool constrain_pitch = true);

            float yaw;
            float pitch;
            float speed;
            float sensitivity;
            static float zoom;

            static bool update_projection;
            static Camera* instance;


            int screen_width;
            int screen_height;


    };

}

#endif
