//
// Created by nic on 4/11/26.
//

#include "GodotFixture.h"
#include "godot_cpp/classes/engine.hpp"
#include "../src/register_types.h"

// actual API
extern "C" {
GDExtensionObjectPtr libgodot_create_godot_instance(int p_argc, char *p_argv[], GDExtensionInitializationFunction p_init_func);
void libgodot_destroy_godot_instance(GDExtensionObjectPtr p_godot_instance);
}

// Empty callbacks for GDExtension initialization
static void initialize_callback(godot::ModuleInitializationLevel level) {
    // Empty - no extension initialization needed
}

static void deinitialize_callback(godot::ModuleInitializationLevel level) {
    // Empty - no extension cleanup needed
}

// GDExtension initialization function
static GDExtensionBool init_callback(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                                    GDExtensionClassLibraryPtr p_library,
                                    GDExtensionInitialization* r_initialization) {


    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
    init_obj.register_initializer(initialize_callback);
    init_obj.register_terminator(deinitialize_callback);
    init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_CORE);
    return init_obj.init();
}

GDExtensionObjectPtr GodotFixture::instance = nullptr;
godot::GodotInstance* GodotFixture::godot_instance = nullptr;
godot::SceneTree* GodotFixture::tree = nullptr;

void GodotFixture::SetUpTestSuite() {
    std::cout << "Starting Godot instance..." << std::endl;

    // Prepare arguments for Godot
    std::vector<std::string> arg_strings = {
        "driver",
        "--path", "project"
    };

    // Convert to char* array
    std::vector<char*> args;
    for (auto& arg : arg_strings) {
        args.push_back(const_cast<char*>(arg.c_str()));
    }

    // Create Godot instance
    instance = libgodot_create_godot_instance(
        args.size(),
        args.data(),
        init_callback
    );

    // Need to call this manually to set up the gdextension for use with this program
    // The godot engine loads the gdextension library at runtime and initializes that,
    // but that doesn't initialize the copy linked to the test binary
    initialize_example_module(MODULE_INITIALIZATION_LEVEL_SCENE);


    if (!instance) {
        std::cerr << "Error creating Godot instance" << std::endl;
        ASSERT_TRUE(false);
    }

    std::cout << "Godot instance created successfully!" << std::endl;

    // Convert GDExtensionObjectPtr to godot::GodotInstance using godot-cpp
    godot::Object* obj = godot::internal::get_object_instance_binding(instance);
    godot_instance = static_cast<godot::GodotInstance*>(obj);

    if (!godot_instance) {
        std::cerr << "Failed to get GodotInstance from GDExtensionObjectPtr" << std::endl;
        libgodot_destroy_godot_instance(instance);
        ASSERT_TRUE(false);
    }

    if (!godot_instance->start()) {
        std::cerr << "Error starting Godot instance" << std::endl;
        libgodot_destroy_godot_instance(instance);
        ASSERT_TRUE(false);
    }

    std::cout << "Godot started successfully!" << std::endl;
    // Get the SceneTree directly
    godot::MainLoop* main_loop = godot::Engine::get_singleton()->get_main_loop();
    tree = godot::Object::cast_to<godot::SceneTree>(main_loop);
}

void GodotFixture::TearDownTestSuite() {
    libgodot_destroy_godot_instance(instance);
}