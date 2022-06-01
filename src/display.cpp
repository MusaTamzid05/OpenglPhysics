#include "display.h"
#include <iostream>



#include <iostream>

#include "rendererGL/cube.h"
#include "rendererGL/time.h"
#include "rendererGL/camera.h"
#include <glm/gtc/matrix_transform.hpp>


namespace Engine {


    Display::Display(const std::string& title,
            int width,
            int height):width(width), height(height) {


        RendererGL::Camera::initialize(Vector3(0.0f, 0.0f, 0.0f), width, height);

        if(!init(title)) {
            std::cerr << "Could not intialize display.\n";
            return;
        }

        std::cout << "Display initialize.\n";

        shapes.push_back(new RendererGL::Cube());
        std::cout.precision(10);
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


        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "could not initialize glad.\n";
            return false;
        }

        return true;
    }

    void Display::draw() {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


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

    }

    void Display::run() {


        if(m_window == nullptr) {
            std::cerr << "could not run.\n";
            return;
        }

        while(!glfwWindowShouldClose(m_window)) {
            handle_input();
            draw();
            update();

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

}
