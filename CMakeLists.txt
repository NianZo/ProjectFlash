cmake_minimum_required(VERSION 3.26)

project(project-flash
        VERSION 1.0
        DESCRIPTION "A game based on an old flash-based MMORPG"
        HOMEPAGE_URL "https://github.com/NianZo/ProjectFlash"
        LANGUAGES CXX
)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(NoInSourceBuilds)

set(CMAKE_CXX_STANDARD 23)

set(GODOT_PROJECT_DIR "project" CACHE STRING "The directory of a Godot project folder")

add_subdirectory(src bin)
add_subdirectory(test)

