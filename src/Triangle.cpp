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
    std::vector<Point> v1 = {points[0],points[1],points[2]};
    std::vector<Point> v2 = {other.points[0],other.points[1],other.points[2]};

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
    Point v0 = points[2] - points[0];
    Point v1 = points[1] - points[0];
    Point v2 = x - points[0];

    double dot00 = v0 * v0;
    double dot01 = v0 * v1;
    double dot02 = v0 * v2;
    double dot11 = v1 * v1;
    double dot12 = v2 * v2;

    double invDenom = 1/(dot00*dot11 - dot01 *dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    return (u >= 0) && (v >= 0) && (u + v <= 1);
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

