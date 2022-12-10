#include "rendererGL/plane.h"
#include "rendererGL/shader.h"
#include "rendererGL/camera.h"


namespace RendererGL {

    PlaneMesh::PlaneMesh() {
	  float vertices[] = {
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

      glGenVertexArrays(1, &VAO);
      glGenBuffers(1, &VBO);
      glBindVertexArray(VAO);
      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
      glEnableVertexAttribArray(1);


    }

    Plane::Plane(Engine::Scene* scene, const  Vector3 position) {
        m_mesh = new PlaneMesh();
        m_shader = new Shader("../shaders/cube.vert", "../shaders/cube.frag");
        transform.set_position(position);
        transform.set_scale(Vector3(20.0f, 1.0f, 20.0f));
        //set_color(Vector3(1.0f, 1.0f, 1.0f));
        

        if(scene == nullptr)
            return;

        btCollisionShape* boxShape = new btBoxShape(btVector3(20, 1, 20.0f));
        btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform(btTransform(btQuaternion(0, 0, 0, 1), btVector3(position.x , position.y, position.z))));
        btScalar mass = 0;
        btVector3 boxInertia(0, 0 ,0);
        boxShape->calculateLocalInertia(mass, boxInertia);

        btRigidBody::btRigidBodyConstructionInfo boxRigidBodyCI(mass, boxMotionState, boxShape, boxInertia);
        boxRigidBody = new btRigidBody(boxRigidBodyCI);
        scene->dynamicsWorld->addRigidBody(boxRigidBody);

    }


    void Plane::render() {
        GameObject::render();
        m_shader->use();

        m_shader->setMat4("projection", Camera::get_instance()->projection);
        m_shader->setMat4("view", Camera::get_instance()->get_view_matrix());
        m_shader->setMat4("model", transform.get_model());
        glBindVertexArray(m_mesh->VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

    }

    void Plane::update() {
        GameObject::update();

        btTransform boxTransform;
        boxRigidBody->getMotionState()->getWorldTransform(boxTransform);
        set_transform(boxTransform);

    }
}
