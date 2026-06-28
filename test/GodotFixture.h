//
// Created by nic on 4/11/26.
//

#ifndef GODOT_CPP_TEMPLATE_GODOTFIXTURE_H
#define GODOT_CPP_TEMPLATE_GODOTFIXTURE_H

#include <gtest/gtest.h>

#include "godot_cpp/classes/godot_instance.hpp"
#include "godot_cpp/classes/scene_tree.hpp"

class GodotFixture : public testing::Test {
protected:
    static void SetUpTestSuite();
    static void TearDownTestSuite();

    static GDExtensionObjectPtr instance;
    static godot::GodotInstance* godot_instance;
    static godot::SceneTree* tree;
};

#endif //GODOT_CPP_TEMPLATE_GODOTFIXTURE_H
