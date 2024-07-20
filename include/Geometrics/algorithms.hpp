

#ifndef PROYECTO_ALGORITHMS_HPP
#define PROYECTO_ALGORITHMS_HPP
#include "Polyhedron.hpp"

namespace algorithms{
    std::pair<bool, Point> rayIntersectsTriangle(Point orig, Point dir, Triangle triangle);
    std::vector<Triangle> triPolyIntersectionComplement(Triangle triangle, Polyhedron P);

    template<typename T>
    bool elementInVector(T element, std::vector<T> vector){
        for (auto i : vector) {
            if (i == element)
                return true;
        }
        return false;
    }

    template<typename T>
    void mergeVectors(std::vector<T>& first, std::vector<T> second){
        first.insert(first.end(),
                             second.begin(),
                             second.end());
    }
}

#endif
