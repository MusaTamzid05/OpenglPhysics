#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

namespace RendererGL {
    struct GameObject;
}


struct Component {
    Component(const std::string& name, RendererGL::GameObject* obj);
    virtual void render() {}
    virtual void update() {}

    RendererGL::GameObject* obj;
    std::string name;
};

#endif
