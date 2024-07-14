#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include "Point.hpp"
#include <iostream>
#include <vector>

class Polyhedron {
private:
    std::vector<Point> vertices;
    int _numberOfVertices;
    double _volume;

public:
    Polyhedron(std::vector<Point> initVertices);

    int numberOfVertices();
    int numberOfFaces();
    double volume();
    std::vector<Point> sortedVertices() const;

    Point& operator[](int i);
    bool operator==(const Polyhedron& other) const;
    std::string toString();

    friend std::ostream& operator<<(std::ostream& os, const Polyhedron& p){
        os << "[";
        for (int i = 0; i < p._numberOfVertices; i++){
            os << p.vertices[i];
            if (i != p._numberOfVertices -1)
                os << ",";
        }
        os << "]";
        return os;
    }
};

#endif
