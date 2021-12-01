//
// Created by Adrián Jaén on 20/11/2021.
//

#include <utility>
#include "../include/Space.h"

Space::Space() {
    used = 0;
}

int Space::getUsed() const{
    return used;
};

Polyhedron Space::operator[](int i) {
    return *polys[i];
}

Polyhedron Space::getPoly(int i) {
    return *polys[i];
}

void Space::addPoly(const Prism& prism) {
    polys[used] = new Prism(prism);
}

void Space::addPoly(const Sphere& sphere) {
    polys[used] = new Sphere(sphere);
}

Space::~Space() {
    *polys = nullptr;
    delete *polys;
}
