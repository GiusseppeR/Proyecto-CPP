#include <Geometrics/algorithms.hpp>
#include <algorithm>
#include <cmath>

std::pair<bool, Point> algorithms::rayIntersectsTriangle(Point orig, Point dir, Triangle triangle) {
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

std::vector<Triangle> algorithms::triPolyIntersectionComplement(Triangle triangle, Polyhedron P) {
    std::vector<Triangle> triangles;
    for(auto face : P.faces){
        auto result = triangle.triangleIntersection(face);

        if (result.size() < 2){
            result = face.triangleIntersection(triangle);
        }

        if (result.size() < 2){
            continue;
        }

        std::vector<Point> t_points = {triangle.points[0],triangle.points[1],triangle.points[2]} ;

        std::sort(result.begin(), result.end(), [](const Point& a, const Point& b) {
            const double EPSILON = 1e-5;
            if (fabs(a.x - b.x) > EPSILON) return a.x < b.x;
            if (fabs(a.y - b.y) > EPSILON) return a.y < b.y;
            return a.z < b.z;
        });
        std::sort(t_points.begin(), t_points.end(), [](const Point& a, const Point& b) {
            const double EPSILON = 1e-5;
            if (fabs(a.x - b.x) > EPSILON) return a.x < b.x;
            if (fabs(a.y - b.y) > EPSILON) return a.y < b.y;
            return a.z < b.z;
        });

        Point first = result[0];
        Point second = result[1];

        int k = 0;

        for(int i = 0; i < 3; i++){
            Point p = t_points[i];
            if(P.rayIntersectsPolyhedron(first, p) || P.rayIntersectsPolyhedron(second,p))
                continue;

            triangles.emplace_back(first,second,p);
            k = i;
            break;
        }

        for(int i = k + 1; i < 3; i++){
            Point p = t_points[i];
            if(P.rayIntersectsPolyhedron(second, p) || P.rayIntersectsPolyhedron(t_points[k], p))
                continue;

            triangles.emplace_back(second, p,t_points[k]);
            if(P.rayIntersectsPolyhedron(second, t_points[(i+1)%3]) || P.rayIntersectsPolyhedron(p, t_points[(i+1)%3]))
                break;

            triangles.emplace_back(p, t_points[(i+1)%3],second);
            break;
        }
    }
    
    return triangles;
}