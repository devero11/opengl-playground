cmake_minimum_required(VERSION 3.10)
project(buildObject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Enable compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${CMAKE_SOURCE_DIR}/includes/glad)
include_directories(${CMAKE_SOURCE_DIR}/includes/GLFW)

# Find GLFW (static or system)
find_package(glfw3 REQUIRED)

# Add GLAD manually (you compile glad.c yourself)
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/src/third_party/glad.c)

# Collect source files (excluding glad.c to avoid duplication)
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.c"
    "src/*.h"
)

# Remove glad.c if it's included by GLOB (avoids double-compilation)
list(REMOVE_ITEM SOURCES ${GLAD_SRC})

# Add executable
add_executable(buildObject ${SOURCES} ${GLAD_SRC})

# Link libraries
target_link_libraries(buildObject PRIVATE glfw GL dl)
