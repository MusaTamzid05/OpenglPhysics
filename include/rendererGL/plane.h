#ifndef PLANE_H
#define PLANE_H

#include "rendererGL/game_object.h"
#include "rendererGL/mesh.h"

namespace RendererGL {

    struct PlaneMesh: public Mesh {
        PlaneMesh();
        virtual ~PlaneMesh() {}

    };

    struct Plane : public GameObject {
        Plane();
        virtual ~Plane() {delete m_mesh;}

        void render();
        void update();

        Mesh* m_mesh;

    };
}

#endif
