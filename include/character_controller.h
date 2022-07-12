#ifndef CHARACTER_CONTROLLER_H
#define CHARACTER_CONTROLLER_H

class CharacterController {
    public:

        static CharacterController* get_instance();
        void reset();

        bool forward;
        bool backward;
        bool left;
        bool right;

    private:
        CharacterController();
        static CharacterController* instance;
};


#endif
