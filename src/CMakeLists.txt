# TODO (nic): This really needs to use the 4.6 branch instead of main, but that doesn't exist yet.
include(FetchContent)
FetchContent_Declare(
        GODOT_CPP
        GIT_REPOSITORY https://github.com/godotengine/godot-cpp.git
        GIT_TAG        10.0.0-rc1
)
FetchContent_MakeAvailable(GODOT_CPP)
target_compile_options(godot-cpp PRIVATE -fno-plt)
set_target_properties(godot-cpp PROPERTIES CXX_VISIBILITY_PRESET "default")
set(LIBNAME "EXTENSION-NAME") # "The name of the library"
add_library(godot-cpp-wrapper SHARED)
#target_sources(godot-cpp-wrapper PRIVATE ${GODOTCPP_SOURCES} ${GENERATED_FILES_LIST}) # The godot-cpp files
target_link_libraries(godot-cpp-wrapper godot-cpp)

add_library(gdextension_shared SHARED)

target_sources(gdextension_shared
        PRIVATE
        register_types.cpp
        register_types.h
        gdexample.cpp
        gdexample.h
        TestObject.cpp
)

target_link_libraries(gdextension_shared PUBLIC godot-cpp-wrapper)
#target_link_libraries(gdextension_shared PUBLIC godot-cpp ${CMAKE_BINARY_DIR}/_deps/godot_cpp-build/libgodot-cpp.linux.template_debug.x86_64.so)
#target_link_libraries(gdextension_shared PUBLIC godot-cpp)
#target_include_directories(gdextension_shared PUBLIC ${CMAKE_BINARY_DIR}/_deps/godot_cpp-build/gen/include godot-cpp/gen/include ${CMAKE_BINARY_DIR}/_deps/godot_cpp-build/gen/include)

set_target_properties(gdextension_shared
        PROPERTIES
        # The generator expression here prevents msvc from adding a Debug or Release subdir.
        RUNTIME_OUTPUT_DIRECTORY "$<1:${PROJECT_SOURCE_DIR}/bin/${GODOTCPP_PLATFORM}>"

        PREFIX ""
        OUTPUT_NAME "libgdextension_shared.${CMAKE_SYSTEM_NAME}.${CMAKE_BUILD_TYPE}.${CMAKE_SYSTEM_PROCESSOR}${GODOTCPP_SUFFIX}"
)

target_compile_options(gdextension_shared PRIVATE -fno-plt)

set(GODOT_PROJECT_BINARY_DIR "${PROJECT_SOURCE_DIR}/${GODOT_PROJECT_DIR}/bin/${GODOTCPP_PLATFORM}")

add_custom_command(TARGET gdextension_shared POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:gdextension_shared>" "${GODOT_PROJECT_BINARY_DIR}/$<TARGET_FILE_NAME:gdextension_shared>"
)