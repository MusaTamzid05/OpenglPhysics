#include "component.h"
#include "rendererGL/shape.h"

Component::Component(const std::string& name, RendererGL::Shape* shape):
    name(name),
    shape(shape) {}
