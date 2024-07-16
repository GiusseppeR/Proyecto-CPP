#include <Geometrics/algorithms.hpp>
#include <Geometrics/Polyhedron.hpp>
#include <Geometrics/Triangle.hpp>
#include <vector>
#include <cmath>
#include <random>

/*
Point algorithms::generateRandomPointOnLine(Point A, Point B) {
    // Random number generator setup
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_real_distribution<> dis(0.0, 1.0); // Define the range

    // Generate a random number between 0 and 1
    double t = dis(gen);

    // Linearly interpolate between points A and B
    double x = A.x + t * (B.x - A.x);
    double y = A.y + t * (B.y - A.y);
    double z = A.z + t * (B.z - A.z);

    return Point(x,y,z);
}

//Algoritmo montecarlo
bool checkLineCutsPolyhedron(Point A, Point B, Polyhedron P){
    int attempts = 1000;
    for(int i = 0; i < attempts; i++){
        Point p = algorithms::generateRandomPointOnLine(A, B);
        if(P.isPointInside(p))
            return true;
    }
    return false;
}

Polyhedron algorithms::computeUnion(Polyhedron P1, Polyhedron P2){
    std::vector<Triangle>output;
    for(auto face : P1.faces){
        auto intersectionLines = face.polyhedronIntersection(P2.faces);
        if(intersectionLines.empty()){
            output.push_back(face);
            continue;
        }

        std::vector<Point> ppointsOutside;
        for (int i = 0; i < 3; i++){
            Point triangleVertex = face.points[i];
            if (P2.isPointInside(triangleVertex)){
                continue;
            }
            ppointsOutside.push_back(triangleVertex);
        }

        for(auto line : intersectionLines){
            Point p1 = line[0];
            Point p2 = line[1];

            std::vector<Point> pointsOutside;
            for(auto point : ppointsOutside){
                if(checkLineCutsPolyhedron(p1,point,P2) && checkLineCutsPolyhedron(p2,point,P2))
                    pointsOutside.push_back(point);
            }

            std::vector<Triangle> trapezoid;
            if(pointsOutside.size() == 1){
                output.emplace_back(line[0],line[1],pointsOutside[0]);
            }

            if(pointsOutside.size() == 2){
                Point a = line[0];
                Point dir1 = a - pointsOutside[0];
                Point ndir1(dir1.x/(dir1*dir1),dir1.y/(dir1*dir1),dir1.z/(dir1*dir1));
                double avg1 = fabs(ndir1.x+ndir1.y+ndir1.z/3);

                Point dir2 = a - pointsOutside[1];
                Point ndir2(dir2.x/(dir2*dir2),dir2.y/(dir2*dir2),dir2.z/(dir2*dir2));
                double avg2 = fabs(ndir2.x+ndir2.y+ndir2.z/3);

                int i = 0;
                if(avg1 < avg2)
                    i = 1;

                output.emplace_back(line[0],pointsOutside[i], line[1]);
                output.emplace_back(line[0],pointsOutside[(i+1)%2],pointsOutside[i]);
            }
        }
    }
    for(auto face : P2.faces)
        output.push_back(face);
    return Polyhedron(output);

}*/
