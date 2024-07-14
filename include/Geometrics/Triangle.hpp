
#ifndef PROYECTO_TRIANGLE_HPP
#define PROYECTO_TRIANGLE_HPP

#include <vector>
#include <Geometrics/Point.hpp>
#include <array>

class Triangle{
private:
    std::array<Point, 3> points;
public:
    Triangle(Point A, Point B, Point C);
    Point& operator[](int i);
    std::string toString();
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
