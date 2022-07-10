#include "rendererGL/shape.h"
#include "rendererGL/shader.h"

namespace RendererGL {

    void Shape::set_color(const Vector3& color) {
        m_shader->use();
        this->color = color;
        m_shader->setVec3("color", glm::vec3(color.x, color.y, color.z));
    }

    void Shape::render() {
        for(Component* component : m_components)
            component->render();
    }


    void Shape::update() {
        for(Component* component : m_components)
            component->update();
    }
}
