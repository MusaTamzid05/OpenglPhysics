#include <iostream>
#include "scene.h"
#include "scenes/collider_test1_scene.h"
#include "scenes/sphere_scene.h"
#include "scenes/bullet_physics_demo_scene.h"
#include "rendererGL/camera.h"

#include <btBulletDynamicsCommon.h>

void bullet_physics_test();
void bullet_physics_scene1();

int main(int argc, char** argv) {
    /*
    Demo::ColliderTest1Scene scene(640, 480);
    scene.run();
    RendererGL::Camera::get_instance()->save(scene.title);
    */

    bullet_physics_scene1();
    return 0;
}


void bullet_physics_test() {
      btBroadphaseInterface* broadphase = new btDbvtBroadphase();

  // Create a collision configuration and a dispatcher
  btDefaultCollisionConfiguration* collisionConfig = new btDefaultCollisionConfiguration();
  btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfig);

  // Create a solver to resolve collisions and simulate rigid bodies
  btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();

  // Create a dynamics world to simulate physics
  btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);

  // Set the gravity of the world
  dynamicsWorld->setGravity(btVector3(0, -10, 0));

  // Create a box shape for our rigid body
  btCollisionShape* boxShape = new btBoxShape(btVector3(1, 1, 1));

  // Create a motion state for the rigid body
  btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 10, 0)));

  // Set the mass and inertia of the box
  btScalar mass = 1;
  btVector3 boxInertia(0, 0, 0);
  boxShape->calculateLocalInertia(mass, boxInertia);

  // Create a rigid body construction info object with the mass, motion state, and shape
  btRigidBody::btRigidBodyConstructionInfo boxRigidBodyCI(mass, boxMotionState, boxShape, boxInertia);

  // Create a rigid body from the construction info
  btRigidBody* boxRigidBody = new btRigidBody(boxRigidBodyCI);

  // Add the rigid body to the world
  dynamicsWorld->addRigidBody(boxRigidBody);

  // Simulate the world for 10 seconds
  for (int i = 0; i < 1000; i++) {
    dynamicsWorld->stepSimulation(0.01, 10);

    // Get the position of the box and print it
    btTransform boxTransform;
    boxRigidBody->getMotionState()->getWorldTransform(boxTransform);
    std::cout << "Box position: " << boxTransform.getOrigin().getX() << ", " << boxTransform.getOrigin().getY() << ", " << boxTransform.getOrigin().getZ() << std::endl;
  }

  // Clean up the objects we created
  delete dynamicsWorld;
  delete solver;
  delete collisionConfig;
  delete dispatcher;
  delete broadphase;
}


void bullet_physics_scene1() {
    Demo::BulletPhysicsDemoScecne scene(640, 480);
    scene.run();
    RendererGL::Camera::get_instance()->save(scene.title);

}
