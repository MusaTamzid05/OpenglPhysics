#include "physics/mover_component.h"
#include "rendererGL/time.h"
#include <iostream>
#include "rendererGL/shape.h"
#include "character_controller.h"

namespace Physics {
    MoveComponent::MoveComponent(RendererGL::Shape* shape, bool gravity_flag, float mass):
        Component(shape),
        gravity_flag(gravity_flag),
        mass(mass)
    {
        position = shape->transform.get_position();
        velocity = Vector3();
        acceleration = Vector3();
    }

    void MoveComponent::render() {
    }

    void MoveComponent::update() {
        if(CharacterController::get_instance()->forward)
            position.y += 0.1f;

        std::cout << "position : x " << position.x << " , y " << position.y << ", z " << position.z << "\n";
        shape->transform.set_position(position);

        /*
        if(gravity_flag) 
            apply_force(Vector3(0.0f, 0.0, 0.0f));



        velocity += acceleration;
        position += (velocity * RendererGL::Time::get_instance()->delta_time);
        shape->transform.set_position(position);

        //std::cout << "position : x " << position.x << " , y " << position.y << ", z " << position.z << "\n";
        std::cout << "velocity : x " << velocity.x << " , y " << velocity.y << ", z " << velocity.z << "\n";
        acceleration *= 0.0f;
        */

    }

    void MoveComponent::apply_force(const Vector3& force) {
        // f = ma
        // a = f / m
        
        Vector3 div_force = force / mass;
        acceleration += div_force;

    }
}
