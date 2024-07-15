#include <Geometrics/Triangle.hpp>

Triangle::Triangle(Point A, Point B, Point C): points({A,B,C}) {}

Point &Triangle::operator[](int i) {
    return points[i];
}

std::string Triangle::toString() {
    std::string result;
    for (int i = 0; i < 3; i++){
        result += points[i].toString() + ";";
    }
    result.pop_back();
    return result;
}

Point Triangle::normal() {
    auto p1 = points[1] - points[0];
    auto p2 = points[2] - points[0];
    return p1.cross(p2);
}