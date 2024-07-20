cmake_minimum_required(VERSION 3.16.3)
project(Proyecto)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(${PROJECT_NAME} main.cpp
        include/Geometrics/algorithms.hpp)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} meshes)