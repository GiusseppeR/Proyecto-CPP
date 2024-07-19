
#ifndef PROYECTO_TRIANGLE_HPP
#define PROYECTO_TRIANGLE_HPP

#include <vector>
#include <Geometrics/Point.hpp>
#include <array>

class Triangle{
public:

    // Constructors
    Triangle() = default;
    Triangle(Point A, Point B, Point C);

    //Attributes
    std::pair<Point, double> plane;
    std::array<Point, 3> points;

    // Methods
    Point normal();
    Point& operator[](int i);
    std::string toString();
    bool isPointInTriangle(Point x);
    std::vector<Point> triangleIntersection(Triangle other);


    friend std::ostream& operator<<(std::ostream& os, const Triangle& p){
        os << "[";
        for (int i = 0; i < 3; i++){
            os << p.points[i];
            if (i != 2)
                os << ",";
        }
        os << "]";
        return os;
    }
};

#endif //PROYECTO_TRIANGLE_HPP
