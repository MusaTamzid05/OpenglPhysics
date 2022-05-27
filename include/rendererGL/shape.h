#ifndef SHAPE_H
#define SHAPE_H

namespace RendererGL {
    class Shader;

    struct Shape {
        Shape() {}
        virtual ~Shape() {}

        virtual void render() = 0;
        virtual void update() = 0;

        Shader* m_shader;


    };
}

#endif
