#include "rendererGL/game_object.h"
#include "rendererGL/shader.h"
#include "component.h"

namespace RendererGL {

    void GameObject::set_color(const Vector3& color) {
        m_shader->use();
        this->color = color;
        m_shader->setVec3("color", glm::vec3(color.x, color.y, color.z));
    }

    void GameObject::render() {
        for(Component* component : m_components)
            component->render();
    }


    void GameObject::update() {
        for(Component* component : m_components)
            component->update();
    }
}
