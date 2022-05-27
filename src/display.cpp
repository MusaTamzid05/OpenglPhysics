#include "display.h"
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>

#include "rendererGL/cube.h"

namespace Engine {


    Display::Display(const std::string& title,
            int width,
            int height):width(width), height(height) {

        if(!init(title)) {
            std::cerr << "Could not intialize display.\n";
            return;
        }

        std::cout << "Display initialize.\n";

        shapes.push_back(new RendererGL::Cube());

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

        for(RendererGL::Shape* shape : shapes)
            shape->update();

    }


    void Display::handle_input() {

        if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window, true);


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


}
