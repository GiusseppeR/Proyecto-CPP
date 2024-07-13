cmake_minimum_required(VERSION 3.16.3)
project(Proyecto)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp
        include/Geometrics/Point.hpp
        include/Geometrics/Polyhedron.hpp)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} meshes)