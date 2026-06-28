//
// Created by nic on 4/10/26.
//

#include "TestObject.h"

#include <cmath>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void TestObject::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_counter"), &TestObject::get_counter);
    ClassDB::bind_method(D_METHOD("set_counter", "p_counter"), &TestObject::set_counter);
    ClassDB::bind_method(D_METHOD("increment_counter", "o", "speed"), &TestObject::increment_counter);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "counter"), "set_counter", "get_counter");
}

TestObject::TestObject() {

}

TestObject::~TestObject() {

}

void TestObject::_process(double delta) {

}

void TestObject::set_counter(const int p_counter) {
    counter = p_counter;
}

int TestObject::get_counter() const {
    return counter;
}

void TestObject::increment_counter(Object* o, float speed) {
    counter++;
}