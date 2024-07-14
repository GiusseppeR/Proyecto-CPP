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
