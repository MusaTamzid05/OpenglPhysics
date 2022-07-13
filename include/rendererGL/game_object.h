#ifndef SHAPE_H
#define SHAPE_H

#include "rendererGL/transform.h"
#include "vector3.h"
#include <vector>

struct Component;

namespace RendererGL {
    class Shader;

    struct GameObject {
        GameObject() {}
        virtual ~GameObject() {}

        virtual void render();
        virtual void update();

        void set_color(const Vector3& color);

        Shader* m_shader;
        Transform transform;

        Vector3 color;
        std::vector<Component*> m_components;

    };
}

#endif
