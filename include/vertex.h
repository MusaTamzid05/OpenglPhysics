#ifndef VERTEX_H
#define VERTEX_H

#include "vector3.h"

struct Vertex {
    Vertex(Vector3 position = Vector3(), Vector3 color = Vector3());
    Vector3 position;
    Vector3 color;
};

#endif
