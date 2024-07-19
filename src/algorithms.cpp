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

std::vector<Triangle> algorithms::triPolyIntersectionComplement(std::vector<Point> intersection_p,
                                                                Triangle triangle, Polyhedron P) {
    if (intersection_p.empty()){
        return {};
    }

    std::vector<Point> intersection;
    for(auto p : intersection_p){
        if(!elementInVector(p,intersection))
            intersection.push_back(p);
    }

    //First: establish the intersection lines
    std::vector<std::pair<Point,Point>> lines;

    for(int i = 0; i < intersection.size()-1; i++){
        Point origin = intersection[i];

        for(int j = i + 1; j < intersection.size(); j++){
            Point destiny = intersection[j];

            Point middle = (destiny + origin) * 0.5;

            if(P.isPointInside(middle))
                continue;

            lines.emplace_back(origin,destiny);
            break;
        }
    }

    //Second: for each line, find  the appropriate points in the triangle
    std::vector<Triangle> triangles;
    for (auto line : lines){
        Point first = line.first;
        Point second = line.second;
        Point tri_first;

        for(auto p : triangle.points){
            if(P.rayIntersectsPolyhedron(first, p))
                continue;

            triangles.emplace_back(first,second,p);
            tri_first = p;
            break;
        }

        for(auto p : triangle.points){
            if (p == tri_first)
                continue;

            if(P.rayIntersectsPolyhedron(second, p))
                continue;

            triangles.emplace_back(second, tri_first, p);
            break;
        }
    }
    return triangles;
}