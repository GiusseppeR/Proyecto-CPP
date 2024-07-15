#include <Geometrics/Polyhedron.hpp>
#include <algorithm>
#include <cmath>

Polyhedron::Polyhedron(std::vector<Triangle> initFaces) {
    faces = initFaces;
    _numberOfFaces = faces.size();
    _volume = -1;
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