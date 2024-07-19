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
    std::vector<Point> faceIntersection(int index, Polyhedron other, bool lookInside);
public:
    Polyhedron() = default;
    Polyhedron(std::vector<Triangle> initFaces);
    std::vector<Triangle> faces;

    bool isPointInside(Point x);
    bool isPointOnSurface(Point x);
    bool rayIntersectsPolyhedron(Point A, Point B);
    double volume();
    std::vector<Point> intersection(Polyhedron other);
    Polyhedron unionPolyhedron(Polyhedron other);

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
