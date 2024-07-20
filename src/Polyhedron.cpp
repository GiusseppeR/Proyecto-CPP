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

bool Polyhedron::rayIntersectsPolyhedron(Point A, Point B) {
    for(auto face : faces){
        auto result = algorithms::rayIntersectsTriangle(A, B,face);
        if(result.first)
            return true;
    }
    return false;
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


std::vector<Point> Polyhedron::faceIntersection(int index, Polyhedron other, bool lookInside) {
    std::vector<Point> intersections;
    Triangle face = this->faces[index];

    for(auto& tri2 : other.faces){
        auto result = face.triangleIntersection(tri2);
        algorithms::mergeVectors(intersections,result);

        if(!lookInside)
            continue;

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
        auto result = faceIntersection(i, other, true);
        algorithms::mergeVectors(intersections,result);
    }

    if (!intersections.empty())
        return intersections;

    for (int i = 0; i < other.faces.size(); i++) {
        auto result = other.faceIntersection(i,*this, true);
        algorithms::mergeVectors(intersections,result);
    }
    return intersections;
}

Polyhedron Polyhedron::unionPolyhedron(Polyhedron other) {
    std::vector<Triangle> unionFaces;
    std::cout << "first:\n";
    for(int i = 0; i < faces.size(); i++){
        Triangle face = this->faces[i];
        if (other.isPointInside(face[0]) &&
        other.isPointInside(face[1]) &&
        other.isPointInside(face[2]))
            continue;

        auto complement = algorithms::triPolyIntersectionComplement(face,other);
        if (complement.empty()){
            unionFaces.push_back(face);
            continue;
        }
        algorithms::mergeVectors(unionFaces,complement);
    }
    std::cout << "second:\n";
    for(int i = 0; i < other.faces.size(); i++){
        Triangle face = other.faces[i];
        if (isPointInside(face[0]) &&
            isPointInside(face[1]) &&
            isPointInside(face[2]))
            continue;

        auto complement = algorithms::triPolyIntersectionComplement(face,*this);
        if (complement.empty()){
            unionFaces.push_back(face);
            continue;
        }
        algorithms::mergeVectors(unionFaces,complement);
    }
    return Polyhedron(unionFaces);
}