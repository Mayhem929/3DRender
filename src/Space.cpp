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
    used++;
}

void Space::addPoly(const Sphere& sphere) {
    polys[used] = new Sphere(sphere);
    used++;
}

Space::~Space() {
    *polys = nullptr;
    delete *polys;
}

void Space::insertionSort(Point3D pos){
    int i, j;
    for (i = 1; i < used; i++) {
        Polyhedron *element = polys[i];
        j = i - 1;
        while (j >= 0 && polys[j]->getCenterPoint().dist(pos) > element->getCenterPoint().dist(pos)) {
            polys[j + 1] = polys[j];
            j--;
        }
        polys[j + 1] = element;
    }
}

std::string Space::to_string() {
    std::string out = "";

    for(int i = 0; i < used; ++i){
        out += "Poly "+std::to_string(i)+":\n" + polys[i]->to_string() + "\n\n";
    }

    return out;
}

