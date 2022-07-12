#include "character_controller.h"

CharacterController* CharacterController::instance = nullptr;

CharacterController::CharacterController() {
    reset();
}

void CharacterController::reset() {
    forward = false;
    backward = false;
    left = false;
    right = false;
}


CharacterController* CharacterController::get_instance() {
    if(instance == nullptr)
        instance = new CharacterController();

    return instance;

}
