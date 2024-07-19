#include <Geometrics/Polyhedron.hpp>
#include <Geometrics/algorithms.hpp>
#include <algorithm>
#include <random>
#include <cmath>
#include <utility>

Polyhedron::Polyhedron(std::vector<Triangle> initFaces) {
    faces = std::move(initFaces);
    _volume = -1;
}


Triangle &Polyhedron::operator[](int i) {
    return faces[i];
}


std::string Polyhedron::toString() {
    std::string result;
    for (int i = 0; i < faces.size(); i++){
        result += faces[i].toString() + ";";
    }
    result.pop_back();
    return result;
}


bool Polyhedron::isPointOnSurface(Point x) {
    for(auto triangle : faces)
        if (triangle.isPointInTriangle(x)) return true;
    return false;
}


bool Polyhedron::isPointInside(Point x) {
    int intersections = 0;
    Point direction = {((double)(rand()%999))/1000, ((double)(rand()%999))/1000, ((double)(rand()%999))/1000}; // Arbitrary direction for the ray

    for (const auto& triangle : faces) {
        if (algorithms::rayIntersectsTriangle(x, direction, triangle).first)
            intersections++;
    }
    // If intersections count is odd, the point is inside the polyhedron
    return intersections % 2 == 1;
}

double Polyhedron::volume() {
    if (_volume != -1)
        return _volume;

    double volume = 0;
    for(auto triangle : faces){
        Point A = triangle[0];
        volume += fabs(A * triangle.normal());
    }

    _volume = volume/6;
    return _volume;
}

std::vector<Point> Polyhedron::faceIntersection(int index, Polyhedron other) {
    std::vector<Point> intersections;
    Triangle face = this->faces[index];

    for(auto& tri2 : other.faces){
        auto result = face.triangleIntersection(tri2);
        algorithms::mergeVectors(intersections,result);

        for (auto p : face.points) {
            if (other.isPointInside(p))
                intersections.push_back(p);
        }
    }
    return intersections;
}

std::vector<Point> Polyhedron::intersection(Polyhedron other) {
    std::vector<Point> intersections;
    for (int i = 0; i < faces.size(); i++) {
        auto result = faceIntersection(i, other);
        algorithms::mergeVectors(intersections,result);
    }

    if (!intersections.empty())
        return intersections;

    for (int i = 0; i < other.faces.size(); i++) {
        auto result = other.faceIntersection(i,*this);
        algorithms::mergeVectors(intersections,result);
    }
    return intersections;
}
