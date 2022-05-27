#ifndef MESH_H
#define MESH_H

namespace RendererGL {
    struct Mesh {
        Mesh() {}
        virtual ~Mesh();

        unsigned int VAO;
        unsigned int VBO;
    };
}

#endif
