#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    double _x;
    double _y;
    double _z;
public:
    Point (): _x(0), _y(0), _z(0) {}
    Point(double x, double y, double z): _x(x), _y(y), _z(z) {}

    double x() const;
    double y() const;
    double z() const;

    double distance(Point target);
    bool operator==(const Point& other) const;
    std::string toString();
    friend std::ostream& operator<<(std::ostream& os, const Point& p){
        os << "(" << p._x << "," << p._y << "," << p._z << ")";
        return os;
    }
};

#endif
