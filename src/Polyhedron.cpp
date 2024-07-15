#include <Geometrics/Polyhedron.hpp>
#include <algorithm>
#include <random>
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

bool Polyhedron::isPointInside(Point x) {
    int intersections = 0;
    Point direction = {((double)(rand()%999))/1000, ((double)(rand()%999))/1000, ((double)(rand()%999))/1000}; // Arbitrary direction for the ray

    for (const auto& triangle : faces) {

        if (rayIntersectsTriangle(x, direction, triangle)) {
            intersections++;
        }
    }

    // If intersections count is odd, the point is inside the polyhedron
    return intersections % 2 == 1;
}

bool Polyhedron::rayIntersectsTriangle(Point orig, Point dir, Triangle triangle) {
    Point p0 = triangle[0];
    Point p1 = triangle[1];
    Point p2 = triangle[2];


    const double EPSILON = 1e-9;
    Point edge1, edge2, h, s, q;
    double a, f, u, v;
    edge1.x = p1.x - p0.x;
    edge1.y = p1.y - p0.y;
    edge1.z = p1.z - p0.z;
    edge2.x = p2.x - p0.x;
    edge2.y = p2.y - p0.y;
    edge2.z = p2.z - p0.z;
    h.x = dir.y * edge2.z - dir.z * edge2.y;
    h.y = dir.z * edge2.x - dir.x * edge2.z;
    h.z = dir.x * edge2.y - dir.y * edge2.x;
    a = edge1.x * h.x + edge1.y * h.y + edge1.z * h.z;
    if (a > -EPSILON && a < EPSILON) {
        return false;    // This ray is parallel to this triangle.
    }
    f = 1.0 / a;
    s.x = orig.x - p0.x;
    s.y = orig.y - p0.y;
    s.z = orig.z - p0.z;
    u = f * (s.x * h.x + s.y * h.y + s.z * h.z);
    if (u < 0.0 || u > 1.0) {
        return false;
    }
    q.x = s.y * edge1.z - s.z * edge1.y;
    q.y = s.z * edge1.x - s.x * edge1.z;
    q.z = s.x * edge1.y - s.y * edge1.x;
    v = f * (dir.x * q.x + dir.y * q.y + dir.z * q.z);
    if (v < 0.0 || u + v > 1.0) {
        return false;
    }
    // At this stage we can compute t to find out where the intersection point is on the line.
    double t = f * (edge2.x * q.x + edge2.y * q.y + edge2.z * q.z);
    if (t > EPSILON) // ray intersection
    {
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
    {
        return false;
    }

    return true;
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