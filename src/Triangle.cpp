#include <Geometrics/Triangle.hpp>
#include <Geometrics/algorithms.hpp>
#include <cmath>
#include <algorithm>

Triangle::Triangle(Point A, Point B, Point C): points({A,B,C}) {
    Point normal = (B-A).cross(C-A);
    double d = -(normal*A);
    plane = {normal,d};
}

Point &Triangle::operator[](int i) {
    return points[i];
}


bool Triangle::operator==(const Triangle &other) const {
    auto v1 = points;
    auto v2 = other.points;

    std::sort(v1.begin(), v1.end(), [](const Point& a, const Point& b) {
        const double EPSILON = 1e-5;
        if (fabs(a.x - b.x) > EPSILON) return a.x < b.x;
        if (fabs(a.y - b.y) > EPSILON) return a.y < b.y;
        return a.z < b.z;
    });

    std::sort(v2.begin(), v2.end(), [](const Point& a, const Point& b) {
        const double EPSILON = 1e-5;
        if (fabs(a.x - b.x) > EPSILON) return a.x < b.x;
        if (fabs(a.y - b.y) > EPSILON) return a.y < b.y;
        return a.z < b.z;
    });

    for (int i = 0; i < 3; i++){
        if (!(v1[i] == v2[i]))
            return false;
    }
    return true;
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

bool Triangle::isPointInTriangle(Point x) {
    if(x == points[0] ||
    x == points[1] ||
    x == points[2])
        return true;

    double planeEquation = x*plane.first + plane.second;
    const double EPSILON = 1e-5;

    if (planeEquation < EPSILON)
        return true;

    return false;
}

std::vector<Point> Triangle::triangleIntersection(Triangle other) {
    std::vector<Point> intersections;
    for (int i = 0; i < 3; i++) {
        Point ray_origin = this->points[i];
        Point ray_destiny = this->points[(i + 1) % 3];
        Point ray_vector = ray_destiny - ray_origin;
        std::pair<bool, Point> ray_intersection = algorithms::rayIntersectsTriangle(ray_origin, ray_vector, other);
        bool does_intersect = ray_intersection.first;
        Point point_intersection = ray_intersection.second;

        if (!does_intersect)
            continue;

        if (point_intersection.isOnSegment(ray_origin, ray_destiny))
            intersections.push_back(point_intersection);
    }
    return intersections;
}

