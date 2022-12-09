#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"
#include <glm/glm.hpp>
#include <string>

namespace RendererGL {
    enum CameraMovement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
        UP,
        DOWN

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
            static void initialize(int width, int height, const std::string& scene_name = "");
            static Camera* get_instance();
            void process_keyboard(CameraMovement direction);
            glm::mat4 get_view_matrix();
            static void process_mouse_scroll(float offset);

            static void process_mouse_movement(float xoffset, float yoffset, bool constrain_pitch = true);
            void update();

            static void rotate(float xoffset, float yoffset, bool constrain_pitch = false);

            static float keyboard_rotation_speed;

            void save(const std::string& path) const;

        private:

            Camera(const Vector3& position, int width, int height);

            Vector3 position;
            static glm::vec3 front;
            static glm::vec3 up;
            static glm::vec3 right;
            static glm::vec3 world_up;

            static void update_camera_vector();
            void init_projection();



            static float yaw;
            static float pitch;
            float speed;
            static float sensitivity;
            static float zoom;

            static bool update_projection;
            static Camera* instance;


            int screen_width;
            int screen_height;


    };

}

#endif
