#ifndef TIME_H
#define TIME_H

namespace RendererGL {
    class Time {

        public:
            static Time* get_instance();
            float delta_time;

            void update();

        private:
            Time();
            virtual ~Time(){}
            static Time* instance;

            float last_frame;

    };
}

#endif
