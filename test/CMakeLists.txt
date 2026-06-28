include(Testing)

include(FetchContent)
FetchContent_Declare(
        GODOT_ENGINE
        GIT_REPOSITORY https://github.com/godotengine/godot.git
        GIT_TAG        4.6.2-stable
)
FetchContent_MakeAvailable(GODOT_ENGINE)

add_custom_target(godot_engine
        COMMAND scons platform=linuxbsd library_type=shared_library extra_suffix=shared_library dev_build=yes debug_symbols=yes scu_build=yes
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/_deps/godot_engine-src
)

add_executable(testApplication testMain.cpp GodotFixture.cpp)
add_dependencies(testApplication godot_engine)
target_link_directories(testApplication PRIVATE ${CMAKE_BINARY_DIR}/_deps/godot_engine-src/bin project/bin/linux)
target_link_libraries(testApplication PRIVATE gdextension_shared libgodot.linuxbsd.editor.dev.x86_64.shared_library.so)
target_include_directories(testApplication PRIVATE godot-cpp/gen/include godot-cpp/include godot-cpp/gdextension ${CMAKE_BINARY_DIR}/_deps/godot_engine-src)

AddTests(testApplication)