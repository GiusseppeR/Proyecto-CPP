#include <Geometrics/Polyhedron.hpp>
#include <algorithm>

Polyhedron::Polyhedron(std::vector<Point> initVertices) {
    vertices = initVertices;
    _numberOfVertices = vertices.size();
}

int Polyhedron::numberOfVertices() {
    return _numberOfVertices;
}

Point &Polyhedron::operator[](int i) {
    return vertices[i];
}

bool Polyhedron::operator==(const Polyhedron &other) const {
    if (_numberOfVertices != other._numberOfVertices)
        return false;

    std::vector<Point> v1(vertices);
    std::vector<Point> v2(other.vertices);

    std::sort(v1.begin(), v1.end(), [](const Point& a, const Point& b) {
        if (a.x() == b.x()) {
            return a.y() < b.y();
        }
        return a.x() < b.x();
    });

    std::sort(v2.begin(), v2.end(), [](const Point& a, const Point& b) {
        if (a.x() == b.x()) {
            return a.y() < b.y();
        }
        return a.x() < b.x();
    });
    for (int i = 0; i < _numberOfVertices; i++){
        if (!(v1[i] == v2[i]))
            return false;
    }
    return true;
}

std::string Polyhedron::toString() {
    std::string result;
    for (int i = 0; i < _numberOfVertices; i++){
        result += vertices[i].toString() + ";";
    }
    result.pop_back();
    return result;
}

double Polyhedron::volume() {
    return 0;
}