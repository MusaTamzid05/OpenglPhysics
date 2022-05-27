#include "rendererGL/mesh.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>


namespace RendererGL {
    Mesh::~Mesh() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }
}
