#ifndef PLANE_H
#define PLANE_H

#include "rendererGL/game_object.h"
#include "rendererGL/mesh.h"
#include <btBulletDynamicsCommon.h>

namespace RendererGL {

    struct PlaneMesh: public Mesh {
        PlaneMesh();
        virtual ~PlaneMesh() {}

    };

    struct Plane : public GameObject {
        Plane(Engine::Scene* scene = nullptr, const  Vector3 position = Vector3());
        virtual ~Plane() {delete m_mesh;}

        void render();
        void update();

        Mesh* m_mesh;
        btRigidBody* boxRigidBody;

    };
}

#endif
