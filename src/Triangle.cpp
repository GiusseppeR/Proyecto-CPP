#include <Geometrics/Triangle.hpp>
#include <Geometrics/algorithms.hpp>
#include <cmath>

Triangle::Triangle(Point A, Point B, Point C): points({A,B,C}) {
    Point normal = (B-A).cross(C-A);
    double d = -(normal*A);
    plane = {normal,d};
}

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

void Triangle::setVertex(Point v, int index){
    points[index] = v;
}

bool Triangle::isPointInTriangle(Point x) {
    if(x == points[0] ||
    x == points[1] ||
    x == points[2])
        return true;

    double planeEquation = x*plane.first + plane.second;
    if (planeEquation < 0.00001)
        return true;

    return false;
}

bool Triangle::checkLineIntersection(Point a, Point b) {
    double u = plane.first*a + plane.second;
    double v = plane.first*b + plane.second;
    if(u*v >= 0)
        return false;
    return true;
}
//call only if the above method returns true
Point Triangle::lineIntersection(Point a, Point b) {
    if (!checkLineIntersection(a,b))
        return Point(INFINITY,INFINITY,INFINITY);

    Point direction = b - a;

    double t = (-(plane.first*a)-plane.second)/(plane.first*direction);

    Point intersection = a + Point(t * direction.x, t * direction.y, t * direction.z);
    return intersection;
}

std::vector<Point> Triangle::triangleIntersection(Triangle t) {
    std::vector<Point> intersections;

    for(int i = 0; i < 3; i++){
        Point p1 = t[i];
        Point p2 = t[(i + 1) % 3];

        if (!checkLineIntersection(p1,p2))
            continue;

        Point intersection = lineIntersection(p1,p2);
        if(isPointInTriangle(intersection))
            intersections.push_back(intersection);
    }
    return intersections;
}

std::vector<std::vector<Point>> Triangle::polyhedronIntersection(std::vector<Triangle> polyhedronFaces) {
    std::vector<std::vector<Point>> intersections;
    for(auto face : polyhedronFaces){
        std::vector<Point> line = face.triangleIntersection(*this);

        if (line.size() > 1){
            intersections.push_back(line);
        }
    }
    return intersections;
}