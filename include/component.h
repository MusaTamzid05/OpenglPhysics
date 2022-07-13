#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

namespace RendererGL {
    struct Shape;
}


struct Component {
    Component(const std::string& name, RendererGL::Shape* shape);
    virtual void render() {}
    virtual void update() {}

    RendererGL::Shape* shape;
    std::string name;
};

#endif
