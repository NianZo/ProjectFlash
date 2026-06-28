#include <iostream>
#include "../src/gdexample.h"
#include "../src/TestObject.h"

#include <gtest/gtest.h>

#include "GodotFixture.h"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/main_loop.hpp"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/classes/window.hpp"

TEST_F(GodotFixture, DoesItWork) {
    // Get the root node of the scene tree
    godot::Window* root = tree->get_root();

    // Get the current scene
    godot::Node* current_scene = tree->get_current_scene();

    godot::GDExample* example = memnew(godot::GDExample);
    std::cout << "Created godot::GDExample class" << std::endl;
    example->set_amplitude(42.0);
    std::cout << "set amplitude" << std::endl;
    std::cout << "amplitude: " << example->get_amplitude() << std::endl;
    std::cout << "got amplitude" << std::endl;

    memdelete(example);
}

TEST_F(GodotFixture, SignalTest) {
    godot::MainLoop* main_loop = godot::Engine::get_singleton()->get_main_loop();
    godot::SceneTree* tree = godot::Object::cast_to<godot::SceneTree>(main_loop);
    godot::Window* root = tree->get_root();
    godot::Node* current_scene = tree->get_current_scene();

    // Can use current_scene->add_child to add nodes dynamically to the scene tree
    // This will probably be useful for building test scenes in code
    godot::GDExample* example = memnew(godot::GDExample);

    // I THINK that the signaler needs to be in the scene tree for signals to work. I'm not sure if the signaled object must be too
    godot::GDExample* scene_example = current_scene->get_node<godot::GDExample>("GDExample"); // TODO (nic) sidenote, the extension's 'reloadable' flag is not set (void ClassDB::register_extension_class(ObjectGDExtension *p_extension) {) which would explain why I've seen this not update in the editor
    godot::TestObject* test = current_scene->get_node<godot::TestObject>("GDExample/Test");

    // Functions connected for signals must be registered via ClassDB::bind_method
    scene_example->connect("position_changed", godot::Callable(test, "increment_counter")); // Failing because neither GDExample nor Test exist in the current scene for this project. This is causing an esoteric segfault here
    scene_example->set_amplitude(4.0);
    scene_example->set_speed(3.0);

    ASSERT_EQ(test->get_counter(), 1);

    memdelete(example);
}