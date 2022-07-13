#include "component.h"
#include "rendererGL/game_object.h"

Component::Component(const std::string& name, RendererGL::GameObject* obj):
    name(name),
    obj(obj) {}
