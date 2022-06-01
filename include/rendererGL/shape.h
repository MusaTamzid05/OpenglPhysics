#ifndef SHAPE_H
#define SHAPE_H

#include "rendererGL/transform.h"

namespace RendererGL {
    class Shader;

    struct Shape {
        Shape() {}
        virtual ~Shape() {}

        virtual void render() = 0;
        virtual void update() = 0;

        Shader* m_shader;

        Transform transform;


    };
}

#endif
