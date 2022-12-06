#ifndef SPHERE_H
#define SPHERE_H

#include "rendererGL/game_object.h"
#include "vertex.h"
#include <vector>

namespace RendererGL {


    struct Sphere : public GameObject {
        static const int NUM_VERTICES = 64;

        Sphere(float radius = 5.0f);
        virtual ~Sphere() {}

        void render();
        void update();

        Vertex vertices[NUM_VERTICES];
        unsigned short indices[NUM_VERTICES];
        int num_vertices;

        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;


    };
}

#endif
