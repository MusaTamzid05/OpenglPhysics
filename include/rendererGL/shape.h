#ifndef SHAPE_H
#define SHAPE_H

#include "rendererGL/transform.h"
#include "vector3.h"

namespace RendererGL {
    class Shader;

    struct Shape {
        Shape() {}
        virtual ~Shape() {}

        virtual void render() = 0;
        virtual void update() = 0;

        void set_color(const Vector3& color);

        Shader* m_shader;
        Transform transform;

        Vector3 color;


    };
}

#endif
