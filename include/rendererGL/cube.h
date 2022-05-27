#ifndef CUBE_H
#define CUBE_H

#include "rendererGL/shape.h"
#include "rendererGL/mesh.h"

namespace RendererGL {

    struct CubeMesh: public Mesh {
        CubeMesh();
        virtual ~CubeMesh() {}

    };

    struct Cube : public Shape {
        Cube();
        virtual ~Cube() {delete m_mesh;}

        void render();
        void update();

        Mesh* m_mesh;

    };
}

#endif
