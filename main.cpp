#include <iostream>
#include <Geometrics/Polyhedron.hpp>
#include <Geometrics/Parser.hpp>


#if 0
int main() {
    std::vector<Point> v = {Point(0,0,0), Point(1,0,0),Point(0,1,0),Point(1,1,0),
                            Point(0,0,1), Point(1,0,1),Point(0,1,1),Point(1,1,1)};
    std::vector<Triangle> t = {
            Triangle(v[0],v[1],v[3]),
            Triangle(v[0],v[2],v[3]),
            Triangle(v[4],v[5],v[7]),
            Triangle(v[4],v[6],v[7]),
            Triangle(v[0],v[4],v[5]),
            Triangle(v[0],v[4],v[6]),
            Triangle(v[0],v[1],v[5]),
            Triangle(v[0],v[2],v[6]),
            Triangle(v[3],v[7],v[5]),
            Triangle(v[3],v[7],v[6]),
            Triangle(v[3],v[1],v[5]),
            Triangle(v[3],v[2],v[6])
    };
    Polyhedron P(t);
    std::cout << P.volume() << std::endl;
    return 0;
}

#else

int main() {
    TriangleParser triangles("../polyhedron.txt");
    auto t = triangles.triangles;
    Polyhedron P(t);
    std::cout << P.volume() << std::endl;
    return 0;
}


#endif