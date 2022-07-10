#include "shape.h"
#include "shader.h"

namespace Engine {


    Shape::Shape(Shader* shader):m_shader(shader) {

    }

    Shape::~Shape() {
        delete m_shader;
    }



};
