#include <Geometrics/Polyhedron.hpp>
#include <algorithm>
#include <random>
#include <cmath>
#include <utility>

Polyhedron::Polyhedron(std::vector<Triangle> initFaces) {
    faces = std::move(initFaces);
    _volume = -1;
}


Triangle &Polyhedron::operator[](int i) {
    return faces[i];
}

std::string Polyhedron::toString() {
    std::string result;
    for (int i = 0; i < faces.size(); i++){
        result += faces[i].toString() + ";";
    }
    result.pop_back();
    return result;
}

bool Polyhedron::isPointOnSurface(Point x) {
    for(auto triangle : faces)
        if (triangle.isPointInTriangle(x)) return true;
    return false;
}

bool Polyhedron::isPointInside(Point x) {
    int intersections = 0;
    Point direction = {((double)(rand()%999))/1000, ((double)(rand()%999))/1000, ((double)(rand()%999))/1000}; // Arbitrary direction for the ray

    for (const auto& triangle : faces) {

        if (rayIntersectsTriangle(x, direction, triangle).first) {
            intersections++;
        }
    }

    // If intersections count is odd, the point is inside the polyhedron
    return intersections % 2 == 1;
}

std::pair<bool, Point> Polyhedron::rayIntersectsTriangle(Point orig, Point dir, Triangle triangle) {
    Point p0 = triangle[0];
    Point p1 = triangle[1];
    Point p2 = triangle[2];


    const double EPSILON = 1e-5;
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
        return std::pair<bool, Point> {false, {}};    // This ray is parallel to this triangle.
    }
    f = 1.0 / a;
    s.x = orig.x - p0.x;
    s.y = orig.y - p0.y;
    s.z = orig.z - p0.z;
    u = f * (s.x * h.x + s.y * h.y + s.z * h.z);
    if (u < 0.0 || u > 1.0) {
        return std::pair<bool, Point> {false, {}};
    }
    q.x = s.y * edge1.z - s.z * edge1.y;
    q.y = s.z * edge1.x - s.x * edge1.z;
    q.z = s.x * edge1.y - s.y * edge1.x;
    v = f * (dir.x * q.x + dir.y * q.y + dir.z * q.z);
    if (v < 0.0 || u + v > 1.0) {
        return std::pair<bool, Point> {false, {}};
    }
    // At this stage we can compute t to find out where the intersection point is on the line.
    double t = f * (edge2.x * q.x + edge2.y * q.y + edge2.z * q.z);
    if (t > EPSILON) // ray intersection
    {
        return std::pair<bool, Point> {true, orig + dir * t};
    }
    else // This means that there is a line intersection but not a ray intersection.
    {
        return std::pair<bool, Point> {false, {}};
    }
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

std::vector<Point> Polyhedron::intersection(Polyhedron other) {
    std::vector<Point> intersections;
    for (auto& tri1: faces) {
        for (auto& tri2: other.faces) {
            for (int i = 0; i < 3; i++) {
                Point ray_origin = tri1[i];
                Point ray_vector = tri1[(i+1)%3];
                std::pair<bool, Point> intersects_point = rayIntersectsTriangle(ray_origin, ray_vector, tri2);
                if (intersects_point.first) {
                    intersections.push_back(intersects_point.second);
                }
            }
        }
    }

    return intersections;
}
