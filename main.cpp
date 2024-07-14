#include <iostream>
#include <Geometrics/Polyhedron.hpp>
#include <Geometrics/Parser.hpp>


#if 0
int main() {
    std::vector<Point> vertices = {
            {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0},  // bottom face
            {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1}   // top face
    };
    Polyhedron P(vertices);

    return 0;
}

#else

int main() {
    TriangleParser triangles("../polyhedron.txt");

    return 0;
}


#endif