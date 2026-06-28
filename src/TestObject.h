//
// Created by nic on 4/10/26.
//

#ifndef GODOT_CPP_TEMPLATE_TESTOBJECT_H
#define GODOT_CPP_TEMPLATE_TESTOBJECT_H

#include "godot_cpp/classes/node2d.hpp"

namespace godot {

    class TestObject : public Node2D {
        GDCLASS(TestObject, Node2D)

    private:
        int counter = 0;

    protected:
        static void _bind_methods();

    public:
        TestObject();
        ~TestObject();

        void _process(double delta) override;

        void set_counter(int p_counter);
        int get_counter() const;

        void increment_counter(Object* o, float speed);
    };
}

#endif //GODOT_CPP_TEMPLATE_TESTOBJECT_H
