#include "rendererGL/camera.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <glm/gtc/matrix_transform.hpp>
#include "rendererGL/time.h"

namespace RendererGL {
    Camera* Camera::instance = nullptr;
    float Camera::zoom = 45.0f;
    bool Camera::update_projection = false;

    Camera::Camera(const Vector3& position, int width, int height):
        position(position) {
            yaw = -90.0f;
            pitch = 0.0f;
            speed = 2.5f;
            sensitivity = 0.1f;
            world_up = glm::vec3(0.0f, 1.0f, 0.0f);
            update_camera_vector();

            screen_width = width;
            screen_height = height;
            init_projection();

        }

    void Camera::initialize(const Vector3& position, int width, int height) {
        instance = new Camera(position, width, height);
    }

    Camera* Camera::get_instance() {
        if(instance == nullptr)
            throw std::runtime_error("Camera not set!!");

        return instance;
    }

    void Camera::update_camera_vector() {
        glm::vec3 front_;
        front_.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front_.y = sin(glm::radians(pitch));
        front_.z = sin(glm::radians(pitch)) * cos(glm::radians(pitch));

        front = glm::normalize(front_);
        right = glm::normalize(glm::cross(front, world_up));
        up = glm::normalize(glm::cross(right, front));


    }


    glm::mat4 Camera::get_view_matrix() {
        glm::vec3 position_= glm::vec3(position.x, position.y, position.z);
        return glm::lookAt(position_, position_ + front, up);
    }

    void Camera::process_keyboard(CameraMovement direction) {
        glm::vec3 position_ = glm::vec3(position.x, position.y, position.z);
        float velocity = speed * Time::get_instance()->delta_time;

        if(direction == FORWARD)
            position_ += front * velocity;

        if(direction == BACKWARD)
            position_ -= front * velocity;

        if(direction == LEFT)
            position_ -= right * velocity;

        if(direction == RIGHT)
            position_ += right * velocity;

        position = Vector3(position_.x, position_.y, position_.z);
    }

    void Camera::process_mouse_scroll(float offset) {
        zoom -= (float)offset;


        if(zoom < 1.0f)
            zoom = 1.0f;
        if(zoom > 45.0f)
            zoom = 45.0f;

        update_projection = true;

    }

    void Camera::process_mouse_movement(float xoffset, float yoffset, bool constrain_pitch) {
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw += xoffset;
        pitch += xoffset;

        if(constrain_pitch) {
            if(pitch > 89.0f)
                pitch = 89.0f;
            if(pitch < -89.0f)
                pitch = -89.0f;
        }
        update_camera_vector();
    }

    void Camera::update() {
        if(update_projection) {
            init_projection();
            update_projection = false;
        }
    }

    void Camera::init_projection() {
        projection = glm::perspective(glm::radians(zoom), (float)screen_width/ (float)screen_height, 0.1f, 100.0f);

    }
}
