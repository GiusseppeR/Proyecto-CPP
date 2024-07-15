#include <Geometrics/Polyhedron.hpp>
#include <algorithm>

Polyhedron::Polyhedron(std::vector<Triangle> initFaces) {
    faces = initFaces;
    _numberOfFaces = faces.size();
}

int Polyhedron::numberOfFaces() {
    return _numberOfFaces;
}

Triangle &Polyhedron::operator[](int i) {
    return faces[i];
}

std::string Polyhedron::toString() {
    std::string result;
    for (int i = 0; i < _numberOfFaces; i++){
        result += faces[i].toString() + ";";
    }
    result.pop_back();
    return result;
}

double Polyhedron::volume() {
    double volume = 0;
    for(auto triangle : faces){
        Point A = triangle[0];
        volume += A * triangle.normal();
    }
    return volume/6;
}