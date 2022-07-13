#include "rendererGL/game_object.h"
#include "rendererGL/shader.h"
#include "component.h"

namespace RendererGL {
    int GameObject::total_game_objects = 0;

    void GameObject::set_color(const Vector3& color) {
        m_shader->use();
        this->color = color;
        m_shader->setVec3("color", glm::vec3(color.x, color.y, color.z));

        id = total_game_objects;
        total_game_objects += 1;
    }

    void GameObject::render() {
        for(Component* component : m_components)
            component->render();
    }


    void GameObject::update() {
        for(Component* component : m_components)
            component->update();

    }



    void GameObject::on_collisions(GameObject* other) {
        std::cout << "collider with " << other->id << "\n";
    }


}
