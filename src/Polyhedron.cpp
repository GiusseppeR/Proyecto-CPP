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

std::vector<Point> Polyhedron::sortedVertices() const {
    std::vector<Point> v(vertices);
    std::sort(v.begin(), v.end(), [](const Point& a, const Point& b) {
        if (a.x() != b.x()) return a.x() < b.x();
        if (a.y() != b.y()) return a.y() < b.y();
        return a.z() < b.z();
    });
    return v;
}

bool Polyhedron::operator==(const Polyhedron &other) const {
    if (_numberOfVertices != other._numberOfVertices)
        return false;

    std::vector<Point> v1 = sortedVertices();
    std::vector<Point> v2 = other.sortedVertices();

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