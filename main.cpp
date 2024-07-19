#include <iostream>
#include <Geometrics/algorithms.hpp>
#include <fstream>
#include <Geometrics/Polyhedron.hpp>
#include <Geometrics/Parser.hpp>


#if 0
int main() {
    TriangleParser parser_tetra("../include/Polyhedra/tetrahedron.txt");
    TriangleParser parser_tetra3("../include/Polyhedra/tetrahedron3.txt");
    TriangleParser parser_polyhedron("../include/Polyhedra/polyhedron.txt");

    Polyhedron tetrahedron(parser_tetra.triangles);
    Polyhedron tetrahedron3(parser_tetra3.triangles);
    Polyhedron polyhedron(parser_polyhedron.triangles);

    std::cout << tetrahedron.volume() << std::endl;

    if (tetrahedron.isPointInside(Point(0.0,0.0,0.0))) {
        std::cout << "The point is inside the polyhedron.\n";
    } else {
        std::cout << "The point is outside the polyhedron.\n";
    }

    TriangleParser parser_hexa("../include/Polyhedra/hexahedron.txt");

    Polyhedron hexahedron(parser_hexa.triangles);
    std::cout << hexahedron;

    if (hexahedron.isPointInside(Point(0.0,0.0,0.0))) {
        std::cout << "The point is inside the polyhedron.\n";
    } else {
        std::cout << "The point is outside the polyhedron.\n";
    }

    //std::vector<Point> points_intersection = tetrahedron.intersection(hexahedron);

    std::cout << tetrahedron;
    std::cout << tetrahedron3;

    //std::vector<Point> points_intersection = tetrahedron.intersection(tetrahedron3);
    //std::vector<Point> points_intersection = tetrahedron3.intersection(tetrahedron);
    std::vector<Point> points_intersection = tetrahedron.intersection(polyhedron);

    std::ofstream input_api;
    input_api.open("../API/input_api.txt");
    input_api << "[";
    for(int i = 0; i < points_intersection.size(); i++) {
        input_api << "[" << points_intersection[i].toString() << "]";
    }
    input_api << "]";
    input_api.close();

    return 0;
}

#else
Polyhedron createCube1() {
    std::vector<Triangle> faces = {
            // Front face
            Triangle(Point(-0.5, -0.5, -0.5), Point(0.5, -0.5, -0.5), Point(0.5, 0.5, -0.5)),
            Triangle(Point(-0.5, -0.5, -0.5), Point(0.5, 0.5, -0.5), Point(-0.5, 0.5, -0.5)),

            // Back face
            Triangle(Point(-0.5, -0.5, 0.5), Point(0.5, -0.5, 0.5), Point(0.5, 0.5, 0.5)),
            Triangle(Point(-0.5, -0.5, 0.5), Point(0.5, 0.5, 0.5), Point(-0.5, 0.5, 0.5)),

            // Bottom face
            Triangle(Point(-0.5, -0.5, -0.5), Point(0.5, -0.5, -0.5), Point(0.5, -0.5, 0.5)),
            Triangle(Point(-0.5, -0.5, -0.5), Point(0.5, -0.5, 0.5), Point(-0.5, -0.5, 0.5)),

            // Top face
            Triangle(Point(-0.5, 0.5, -0.5), Point(0.5, 0.5, -0.5), Point(0.5, 0.5, 0.5)),
            Triangle(Point(-0.5, 0.5, -0.5), Point(0.5, 0.5, 0.5), Point(-0.5, 0.5, 0.5)),

            // Left face
            Triangle(Point(-0.5, -0.5, -0.5), Point(-0.5, 0.5, -0.5), Point(-0.5, 0.5, 0.5)),
            Triangle(Point(-0.5, -0.5, -0.5), Point(-0.5, 0.5, 0.5), Point(-0.5, -0.5, 0.5)),

            // Right face
            Triangle(Point(0.5, -0.5, -0.5), Point(0.5, 0.5, -0.5), Point(0.5, 0.5, 0.5)),
            Triangle(Point(0.5, -0.5, -0.5), Point(0.5, 0.5, 0.5), Point(0.5, -0.5, 0.5))
    };
    return Polyhedron(faces);
}

Polyhedron createCube2() {
    std::vector<Triangle> faces = {
            // Front face
            Triangle(Point(0.0, -0.5, -0.5), Point(1.0, -0.5, -0.5), Point(1.0, 0.5, -0.5)),
            Triangle(Point(0.0, -0.5, -0.5), Point(1.0, 0.5, -0.5), Point(0.0, 0.5, -0.5)),

            // Back face
            Triangle(Point(0.0, -0.5, 0.5), Point(1.0, -0.5, 0.5), Point(1.0, 0.5, 0.5)),
            Triangle(Point(0.0, -0.5, 0.5), Point(1.0, 0.5, 0.5), Point(0.0, 0.5, 0.5)),

            // Bottom face
            Triangle(Point(0.0, -0.5, -0.5), Point(1.0, -0.5, -0.5), Point(1.0, -0.5, 0.5)),
            Triangle(Point(0.0, -0.5, -0.5), Point(1.0, -0.5, 0.5), Point(0.0, -0.5, 0.5)),

            // Top face
            Triangle(Point(0.0, 0.5, -0.5), Point(1.0, 0.5, -0.5), Point(1.0, 0.5, 0.5)),
            Triangle(Point(0.0, 0.5, -0.5), Point(1.0, 0.5, 0.5), Point(0.0, 0.5, 0.5)),

            // Left face
            Triangle(Point(0.0, -0.5, -0.5), Point(0.0, 0.5, -0.5), Point(0.0, 0.5, 0.5)),
            Triangle(Point(0.0, -0.5, -0.5), Point(0.0, 0.5, 0.5), Point(0.0, -0.5, 0.5)),

            // Right face
            Triangle(Point(1.0, -0.5, -0.5), Point(1.0, 0.5, -0.5), Point(1.0, 0.5, 0.5)),
            Triangle(Point(1.0, -0.5, -0.5), Point(1.0, 0.5, 0.5), Point(1.0, -0.5, 0.5))
    };
    return Polyhedron(faces);
}

int main() {
    Polyhedron cube1 = createCube1();
    Polyhedron cube2 = createCube2();

    std::vector<Triangle> lol;

    for(auto face : cube2.faces){
        Point p1 = Point(face[0].x,face[0].y*0.5,face[0].z*0.5);
        Point p2 = Point(face[1].x,face[1].y*0.5,face[1].z*0.5);
        Point p3 = Point(face[2].x,face[2].y*0.5,face[2].z*0.5);
        lol.emplace_back(p1,p2,p3);
    }
    Point p(1,-0.5,-0.3);
    auto cube3 = Polyhedron(lol);



    //for (auto p : cube1.intersection(cube3))
    //    std::cout << p << ",";
    std::cout << cube1.unionPolyhedron(cube3) << std::endl;


    return 0;
}


#endif