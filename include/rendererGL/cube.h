#ifndef CUBE_H
#define CUBE_H

#include "rendererGL/game_object.h"
#include "rendererGL/mesh.h"
#include "scene.h"
#include <btBulletDynamicsCommon.h>

namespace RendererGL {

    struct CubeMesh: public Mesh {
        CubeMesh();
        virtual ~CubeMesh() {}

    };

    struct Cube : public GameObject {
        Cube(Engine::Scene* scene = nullptr, const  Vector3 position = Vector3());
        virtual ~Cube() {delete m_mesh;}

        void render();
        void update();

        Mesh* m_mesh;
        btRigidBody* boxRigidBody;



    };
}

#endif
