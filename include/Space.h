//
// Created by Adrián Jaén on 20/11/2021.
//

#ifndef SPACE_H
#define SPACE_H

#include "Sphere.h"
#include "Prism.h"
#include "Polyhedron.h"


class Space {

private:
    Polyhedron *polys[100]{};
    int used;

public:
    Space();

    Polyhedron getPoly(int i);

    void addPoly(const Prism& prism);
    void addPoly(const Sphere& sphere);

    int getUsed() const;

    ~Space();

    Polyhedron* operator[](int);

    void insertionSortR(Point3D pos);

    std::string to_string();
};


#endif // SPACE_H
