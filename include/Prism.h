//
// Created by Adrián Jaén on 21/11/2021.
//

#ifndef INC_3DBOX_PRISM_H
#define INC_3DBOX_PRISM_H
#include "GraphicsGems.h"

#define NUMDIM	3
#define RIGHT	0
#define LEFT	1
#define MIDDLE	2

#include "Point3D.h"
#include "Vector3D.h"
#include "Line3D.h"
#include "Polyhedron.h"
#include "cmath"

class Prism: public Polyhedron{
private:
    Point3D minB, maxB;
public:

    Prism();
    Prism(Point3D, Point3D);

    Point3D& getLb();
    Point3D& getRt();

    Point3D getCenterPoint() override;

    bool Intersect(Line3D l, Point3D &coord) override;
    std::string to_string();
};


#endif //INC_3DBOX_PRISM_H
