#ifndef SHAPE_H
#define SHAPE_H

#include "rendererGL/transform.h"
#include "vector3.h"
#include <vector>
#include "scene.h"

struct Component;

namespace RendererGL {
    class Shader;

    struct GameObject {
        GameObject(Engine::Scene* scene = nullptr):scene(scene) {}
        virtual ~GameObject() {}

        virtual void render();
        virtual void update();

        void set_color(const Vector3& color);

        void set_transform(btTransform bt_transform);

        Shader* m_shader;
        Transform transform;

        Vector3 color;
        std::vector<Component*> m_components;

        virtual void on_collisions(GameObject* other);

        static int total_game_objects;
        int id;

        Engine::Scene* scene;

    };
}

#endif
