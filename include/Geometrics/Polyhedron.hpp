#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include "Triangle.hpp"
#include "Point.hpp"
#include <iostream>
#include <vector>
#include <utility>

class Polyhedron {
private:
    double _volume;

public:
    Polyhedron() = default;
    Polyhedron(std::vector<Triangle> initFaces);
    std::vector<Triangle> faces;

    bool isPointInside(Point x);
    bool isPointOnSurface(Point x);
    std::pair<bool, Point> rayIntersectsTriangle(Point orig, Point dir, Triangle triangle);
    double volume();
    std::vector<Point> intersection(Polyhedron other);

    Triangle& operator[](int i);
    std::string toString();

    friend std::ostream& operator<<(std::ostream& os, const Polyhedron& p){
        for (auto triangle : p.faces){
            os << triangle << "," << std::endl;
        }
        return os;
    }
};

#endif
