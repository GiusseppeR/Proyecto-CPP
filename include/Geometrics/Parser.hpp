#ifndef PROYECTO_PARSER_HPP
#define PROYECTO_PARSER_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include <string>

#include "Triangle.hpp"

class TriangleParser {
public:
    std::vector<Triangle> triangles;

    TriangleParser(std::string path);
};

#endif
