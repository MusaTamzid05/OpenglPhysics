#ifndef COMPONENT_H
#define COMPONENT_H

namespace RendererGL {
    struct Shape;
}


struct Component {
    Component(RendererGL::Shape* shape);
    virtual void render() {}
    virtual void update() {}

    RendererGL::Shape* shape;
};

#endif
