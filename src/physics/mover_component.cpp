#include "physics/mover_component.h"
#include "rendererGL/time.h"
#include <iostream>
#include "rendererGL/game_object.h"
#include "character_controller.h"

namespace Physics {
    MoveComponent::MoveComponent(RendererGL::GameObject* obj, bool gravity_flag, float mass):
        Component("move_component",obj),
        gravity_flag(gravity_flag),
        mass(mass)
    {
        position = obj->transform.get_position();
        velocity = Vector3();
        acceleration = Vector3();
    }

    void MoveComponent::render() {
    }

    void MoveComponent::update() {
        if(gravity_flag) 
            apply_force(Vector3(0.0f, -9.8, 0.0f));



        velocity += acceleration;
        position += (velocity * RendererGL::Time::get_instance()->delta_time);
        obj->transform.set_position(position);

        acceleration *= 0.0f;

    }

    void MoveComponent::apply_force(const Vector3& force) {
        // f = ma
        // a = f / m
        
        Vector3 div_force = force / mass;
        acceleration += div_force;

    }
}
