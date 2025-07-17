cmake_minimum_required(VERSION 3.10)
project(buildObject)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${CMAKE_SOURCE_DIR}/includes/glad)
include_directories(${CMAKE_SOURCE_DIR}/includes/GLFW)

find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "src/*.h")


add_executable(buildObject ${SOURCES})

target_link_libraries(buildObject PRIVATE glfw GL dl)
