set(HPP_LIST "${PROJECT_SOURCE_DIR}/include/Circle/circle.hpp")
set(CPP_LIST "circle.cpp")

add_library(meshes ${CPP_LIST} ${HPP_LIST})
target_include_directories(meshes PUBLIC ../include)