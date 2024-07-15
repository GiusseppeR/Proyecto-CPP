#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
    double x;
    double y;
    double z;

    Point (): x(0), y(0), z(0) {}
    Point(double x, double y, double z): x(x), y(y), z(z) {}

    double distance(Point target);
    double operator*(Point other);
    Point operator+(Point other);
    Point operator-(Point other);
    Point cross(Point other);
    bool operator==(const Point& other) const;
    std::string toString();
    friend std::ostream& operator<<(std::ostream& os, const Point& p){
        os << "(" << p.x << "," << p.y << "," << p.z << ")";
        return os;
    }
};
#endif
