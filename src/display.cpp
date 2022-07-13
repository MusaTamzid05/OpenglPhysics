#include "display.h"
#include <iostream>



#include <iostream>

#include "rendererGL/cube.h"
#include "rendererGL/time.h"
#include "rendererGL/camera.h"
#include "physics/mover_component.h"
#include "physics/box_component.h"
#include <glm/gtc/matrix_transform.hpp>

#include "character_controller.h"

namespace Engine {
    bool Display::first_move = true;
    float Display::last_x = 0.0f;
    float Display::last_y = 0.0f;

    Display::Display(const std::string& title,
            int width,
            int height):width(width), height(height) {


        RendererGL::Camera::initialize(width, height);

        if(!init(title)) {
            std::cerr << "Could not intialize display.\n";
            return;
        }

        std::cout << "Display initialize.\n";

        shapes.push_back(new RendererGL::Cube());
        shapes[0]->set_color(Vector3(0.0f, 0.5f, 0.0f));
        shapes[0]->transform.set_position(Vector3(0.0f, 0.0f, 0.0f));
        shapes[0]->m_components.push_back(new Physics::MoveComponent(shapes[0]));

        RendererGL::Cube* plane = new RendererGL::Cube();
        plane->transform.set_position(Vector3(0.0f, -10.0f, 0.0f));
        plane->transform.set_scale(Vector3(20.0f, 1.0f, 20.0f));
        plane->set_color(Vector3(0.7f, 0.5f, 0.3f));

        shapes.push_back(plane);

        std::cout.precision(10);

        last_x = width / 2.0f;
        last_y = height / 2.0f;
        glEnable(GL_DEPTH_TEST); 
    }

    Display::~Display() {

        for(RendererGL::Shape* shape : shapes)
            delete shape;

        glfwTerminate();
    }

    bool Display::init(const std::string& title) {

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width,
                height,
                title.c_str(),
                nullptr,
                nullptr
                );

        if(m_window == nullptr) {
            std::cerr << "could not initialize glfw.\n";
            return false;
        }

        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
        glfwSetScrollCallback(m_window, scroll_callback);
        glfwSetCursorPosCallback(m_window, mouse_callback);


        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "could not initialize glad.\n";
            return false;
        }

        return true;
    }

    void Display::draw() {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


        for(RendererGL::Shape* shape : shapes)
            shape->render();
    }

    void Display::update() {

        RendererGL::Time::get_instance()->update();
        RendererGL::Camera::get_instance()->update();

        for(RendererGL::Shape* shape : shapes)
            shape->update();

    }


    void Display::handle_input() {

        if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window, true);

	  if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
			RendererGL::Camera::get_instance()->process_keyboard(RendererGL::CameraMovement::FORWARD);

		if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
			RendererGL::Camera::get_instance()->process_keyboard(RendererGL::CameraMovement::BACKWARD);

		if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
			RendererGL::Camera::get_instance()->process_keyboard(RendererGL::CameraMovement::LEFT);

		if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
			RendererGL::Camera::get_instance()->process_keyboard(RendererGL::CameraMovement::RIGHT);

        // rotating ..
        if (glfwGetKey(m_window, GLFW_KEY_KP_4) == GLFW_PRESS) {
			RendererGL::Camera::get_instance()->rotate(-RendererGL::Camera::keyboard_rotation_speed, 0.0f, true);
        } else if (glfwGetKey(m_window, GLFW_KEY_KP_6) == GLFW_PRESS) {
			RendererGL::Camera::get_instance()->rotate(RendererGL::Camera::keyboard_rotation_speed, 0.0f, true);
        } else if(glfwGetKey(m_window, GLFW_KEY_KP_8) == GLFW_PRESS) {
			RendererGL::Camera::get_instance()->rotate(0.0f, RendererGL::Camera::keyboard_rotation_speed, true);
        } else if(glfwGetKey(m_window, GLFW_KEY_KP_2) == GLFW_PRESS) {
			RendererGL::Camera::get_instance()->rotate(0.0f, -RendererGL::Camera::keyboard_rotation_speed, true);

        }

        CharacterController::get_instance()->reset();

        if(glfwGetKey(m_window, GLFW_KEY_UP)) {
            CharacterController::get_instance()->forward = true;
        }

        if(glfwGetKey(m_window, GLFW_KEY_DOWN)) {
            CharacterController::get_instance()->backward = true;
        }



    }

    void Display::run() {


        if(m_window == nullptr) {
            std::cerr << "could not run.\n";
            return;
        }

        while(!glfwWindowShouldClose(m_window)) {
            handle_input();
            update();
            draw();

            glfwSwapBuffers(m_window);
            glfwPollEvents();

            
        }
    }


    void Display::framebuffer_size_callback(GLFWwindow* window,
            int width,
            int height) {
        glViewport(0, 0, width, height);
    }

    void Display::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
        RendererGL::Camera::process_mouse_scroll(static_cast<float>(yoffset));
    }

    void Display::mouse_callback(GLFWwindow* window, double xpos_in, double ypos_in) {


        float xpos = static_cast<float>(xpos_in);
        float ypos = static_cast<float>(ypos_in);

        if(first_move) {
            last_x = xpos;
            last_y = ypos;
            first_move = false;
        }

        float xoffset = xpos - last_x;
        float yoffset = last_y - ypos;

        last_x = xpos;
        last_y = ypos;
        RendererGL::Camera::get_instance()->process_mouse_movement(xoffset, yoffset);


    }

    void Display::update_collisions() {
        if(shapes.size() < 2)
            return;

        for(unsigned int i = 0; i < shapes.size(); i += 1) {
            for(Component* component : shapes[i]->m_components) {
                if(component->name != "box_component")
                    continue;

                for(unsigned int j = 0; j < shapes.size(); j += 1) {
                    if(i == j)
                        continue;

                    for(Component* component2: shapes[j]->m_components) {
                        if(component2->name != "box_component")
                            continue;

                        Physics::BoxComponent* box1 =  (Physics::BoxComponent*) component;
                        Physics::BoxComponent* box2 =  (Physics::BoxComponent*) component2;

                        if(Physics::AABB::intersect(box1->aabb, box2->aabb)) { std::cout << "collision.\n"; }

                    }
                }
            }

        }

    }

}
