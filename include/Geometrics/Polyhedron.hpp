#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include "Triangle.hpp"
#include "Point.hpp"
#include <iostream>
#include <vector>

class Polyhedron {
private:
    std::vector<Triangle> faces;
    int _numberOfFaces;
    double _volume;

    // Check if a ray intersects a triangle using the Möller-Trumbore intersection algorithm

public:
    Polyhedron(std::vector<Triangle> initFaces);

    int numberOfVertices();
    int numberOfFaces();
    bool isPointInside(Point x);
    bool rayIntersectsTriangle(Point orig, Point dir, Triangle triangle);
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
