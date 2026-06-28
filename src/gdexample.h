//
// Created by nic on 3/22/26.
//

#ifndef GDEXTENSION_CPP_EXAMPLE_GDEXAMPLE_H
#define GDEXTENSION_CPP_EXAMPLE_GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include "TestObject.h"

namespace godot {

    class GDExample : public Sprite2D {
        GDCLASS(GDExample, Sprite2D)

    private:
        double time_passed;
        double time_emit;
        double amplitude;
        double speed;
        TestObject* test;

    protected:
        static void _bind_methods();

    public:
        GDExample();
        ~GDExample();

        void _process(double delta) override;

        void set_amplitude(const double p_amplitude);
        double get_amplitude() const;

        void set_speed(const double p_speed);
        double get_speed() const;
    };
}

#endif // GDEXTENSION_CPP_EXAMPLE_GDEXAMPLE_H
