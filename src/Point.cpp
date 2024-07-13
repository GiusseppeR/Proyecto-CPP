#include <Geometrics/Point.hpp>
#include <cmath>
#include <sstream>

double Point::x() const {
    return _x;
}

double Point::y() const {
    return _y;
}

double Point::z() const {
    return _z;
}

double Point::distance(Point target) {
    double dx = _x - target._x;
    double dy = _y - target._y;
    double dz = _z - target._z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

bool Point::operator==(const Point &other) const {
    constexpr double epsilon = static_cast<double>(1e-5);

    return std::fabs(_x - other._x) <= epsilon &&
    std::fabs(_y - other._y) <= epsilon &&
    std::fabs(_z - other._z) <= epsilon;
}

std::string Point::toString() {
    std::ostringstream os ;
    os << _x << "," << _y << "," << _z;
    return os.str();
}

