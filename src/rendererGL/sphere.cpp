#include "rendererGL/sphere.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "rendererGL/shader.h"
#include "rendererGL/camera.h"

namespace RendererGL {
    Sphere::Sphere(float radius):num_vertices(64) {
        float angle = 2 * M_PI / num_vertices;
        Vector3 color(1, 1, 1);

        for(int i = 0; i < num_vertices; i += 1) {
            float x = radius * cos(i * angle);
            float y = radius * sin(i * angle);
            float z = 0.0f;


            Vector3 position(x, y, z);
            vertices[i] = position;
        }

        for(int i = 0; i < NUM_VERTICES; i += 1) 
            indices[i] = i;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);


        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        glEnableVertexAttribArray(0);



        m_shader = new Shader("../shaders/sphere.vert", "../shaders/sphere.frag");
        transform.set_position(Vector3(-2.0f, 0.0f, 0.0f));
        set_color(Vector3(1.0f, 1.0f, 1.0f));

    }

    void Sphere::render() {
        GameObject::render();
        m_shader->use();

        m_shader->setMat4("projection", Camera::get_instance()->projection);
        m_shader->setMat4("view", Camera::get_instance()->get_view_matrix());
        m_shader->setMat4("model", transform.get_model());

        std::cout << "drawing\n";
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLE_FAN, num_vertices, GL_UNSIGNED_SHORT, 0);

    }

    void Sphere::update() {
        GameObject::update();
        //Physics::MoveComponent* mover = (Physics::MoveComponent*) &m_components[0];
        //std::cout << mover->position.x << " " << mover->position.y << " " << mover->position.z << "\n";
        //transform.set_position(m_components[0]->position);

    }
}
