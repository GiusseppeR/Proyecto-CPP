set(HPP_LIST "${PROJECT_SOURCE_DIR}/include/Geometrics/Point.hpp"
        "${PROJECT_SOURCE_DIR}/include/Geometrics/Polyhedron.hpp")
set(CPP_LIST "Point.cpp"
        Polyhedron.cpp)

add_library(meshes ${CPP_LIST} ${HPP_LIST})
target_include_directories(meshes PUBLIC ../include)