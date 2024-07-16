

#ifndef PROYECTO_ALGORITHMS_HPP
#define PROYECTO_ALGORITHMS_HPP
#include "Polyhedron.hpp"

namespace algorithms{
    Polyhedron computeUnion( Polyhedron P1,  Polyhedron P2);
    Point generateRandomPointOnLine(Point A, Point B);
}

#endif
