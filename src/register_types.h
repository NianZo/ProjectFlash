//
// Created by nic on 3/23/26.
//

#ifndef GDEXTENSION_CPP_EXAMPLE_REGISTER_TYPES_H
#define GDEXTENSION_CPP_EXAMPLE_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level);
void uninitialize_example_module(ModuleInitializationLevel p_level);

extern "C"
{
    GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization);
}

#endif // GDEXTENSION_CPP_EXAMPLE_REGISTER_TYPES_H
