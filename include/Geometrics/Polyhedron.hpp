#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include "Triangle.hpp"
#include <iostream>
#include <vector>

class Polyhedron {
private:
    std::vector<Triangle> faces;
    int _numberOfFaces;
    double _volume;

public:
    Polyhedron(std::vector<Triangle> initFaces);

    int numberOfVertices();
    int numberOfFaces();
    double volume();

    Triangle& operator[](int i);
    std::string toString();

    friend std::ostream& operator<<(std::ostream& os, const Polyhedron& p){
        for (auto triangle : p.faces){
            os << triangle << std::endl;
        }
        return os;
    }
};

#endif
