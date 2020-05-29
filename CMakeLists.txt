cmake_minimum_required(VERSION 3.13)
project(minirend)

set(CMAKE_CXX_STANDARD 11)
set(OpenGL_GL_PREFERENCE GLVND)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(examples)
