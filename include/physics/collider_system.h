#ifndef COLLIDER_SYSTEM_H
#define COLLIDER_SYSTEM_H

#include <vector>

namespace RendererGL {
    struct Shape;
};

namespace Physics {
    class ColliderSystem {

        public:
            static ColliderSystem* get_instance();
            std::vector<RendererGL::Shape*> shapes;
            void update();

        private:
            ColliderSystem();
            static ColliderSystem* instance;

            bool collided(const RendererGL::Shape* shape1, const RendererGL::Shape* shape2) const;

    };
}

#endif
