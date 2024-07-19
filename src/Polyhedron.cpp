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

    //Point direction = {10,15,10};

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
    edge1 = p1 - p0;
    edge2 = p2- p0;
    h = dir.cross(edge2);
    a = edge1 * h;
    if (a > -EPSILON && a < EPSILON) {
        return std::pair<bool, Point> {false, {}};    // This ray is parallel to this triangle.
    }
    f = 1.0 / a;
    s = orig - p0;
    u = f * (s * h);
    if (u < 0.0 || u > 1.0) {
        return std::pair<bool, Point> {false, {}};
    }
    q = s.cross(edge1);
    v = f * (dir * q);
    if (v < 0.0 || u + v > 1.0) {
        return std::pair<bool, Point> {false, {}};
    }
    // At this stage we can compute t to find out where the intersection point is on the line.
    double t = f * (edge2 * q);
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
                Point ray_vector = tri1[(i+1)%3] - ray_origin;
                std::pair<bool, Point> ray_intersection = rayIntersectsTriangle(ray_origin, ray_vector, tri2);
                bool does_intersect = ray_intersection.first;
                Point point_intersection = ray_intersection.second;
                if (does_intersect) {
                    if (point_intersection.isOnSegment(tri1[i], tri1[(i+1)%3])) {
                        intersections.push_back(point_intersection);
                    } else {
                        //if (point_intersection.distance(tri1[(i+1)%3]) > point_intersection.distance(tri1[i]))
                        //    intersections.push_back(tri1[i]);
                        //else
                        if (other.isPointInside(tri1[(i+1)%3]))
                            intersections.push_back(tri1[(i+1)%3]);

                    }
                }
            }
        }

    }

    if (intersections.empty())
        return intersections;

    for (auto& tri1: other.faces) {
        for (auto& tri2: faces) {
            for (int i = 0; i < 3; i++) {
                Point ray_origin = tri1[i];
                Point ray_vector = tri1[(i+1)%3] - ray_origin;
                std::pair<bool, Point> ray_intersection = rayIntersectsTriangle(ray_origin, ray_vector, tri2);
                bool does_intersect = ray_intersection.first;
                Point point_intersection = ray_intersection.second;
                if (does_intersect) {
                    if (point_intersection.isOnSegment(tri1[i], tri1[(i+1)%3])) {
                        intersections.push_back(point_intersection);
                    } else {
                        //if (point_intersection.distance(tri1[(i+1)%3]) > point_intersection.distance(tri1[i]))
                        //    intersections.push_back(tri1[i]);
                        //else
                        if (isPointInside(tri1[(i+1)%3]))
                            intersections.push_back(tri1[(i+1)%3]);

                    }
                }
            }
        }

    }

    return intersections;

}
