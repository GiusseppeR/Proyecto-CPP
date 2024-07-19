#include <Geometrics/Point.hpp>
#include <cmath>
#include <sstream>

double Point::distance(Point target) {
    double dx = x - target.x;
    double dy = y - target.y;
    double dz = z - target.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

double Point::operator*(Point other) {
    return x*other.x + y*other.y + z*other.z;
}

Point Point::operator+(Point other) {
    return Point(x + other.x, y + other.y, z + other.z);
}

Point Point::operator-(Point other) {
    return Point(x - other.x, y - other.y, z - other.z);
}

Point Point::operator*(double scalar) {
    return Point(scalar * x, scalar * y, scalar * z);
}

Point Point::cross(Point other) {
    double _x = y*other.z - z*other.y;
    double _y = z*other.x - x*other.z;
    double _z = x*other.y - y*other.x;
    return Point(_x,_y,_z);
}

bool Point::operator==(const Point &other) const {
    constexpr double epsilon = static_cast<double>(1e-5);

    return std::fabs(x - other.x) <= epsilon &&
    std::fabs(y - other.y) <= epsilon &&
    std::fabs(z - other.z) <= epsilon;
}

// Function to check if the point is between the segment AB
bool Point::isOnSegment(Point a, Point b) {
    Point c = *this;
    Point d = b - a;

    // Solve for parameter t
    double t = ((c - a) * d) / (d*d);

    // Check if 0 <= t <= 1
    return (t >= 0 && t <= 1);
}

std::string Point::toString() {
    std::ostringstream os ;
    os << x << "," << y << "," << z;
    return os.str();
}

