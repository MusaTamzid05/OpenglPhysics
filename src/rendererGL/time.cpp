#include "rendererGL/time.h"
#include <GLFW/glfw3.h>
#include <iostream>

namespace RendererGL {
    Time* Time::instance = nullptr;

    Time::Time() {
        last_frame = 0.0f;
        delta_time = 0.0f;
    }

    Time* Time::get_instance() {
        if(instance == nullptr)
            instance = new Time();

        return instance;
    }

    void Time::update() {
        float current_frame = static_cast<float>(glfwGetTime());
        delta_time = current_frame - last_frame;
        last_frame = current_frame;
    }

}
