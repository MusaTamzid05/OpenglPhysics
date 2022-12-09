#ifndef BULLET_PHYSICS_DEMO_SCENE_H
#define BULLET_PHYSICS_DEMO_SCENE_H


#include "scene.h"


namespace Demo {
    class BulletPhysicsDemoScecne : public Engine::Scene {
        public:

            BulletPhysicsDemoScecne( 
                    int width = 640,
                    int height = 480
                    );

    };
}


#endif
