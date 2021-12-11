//
// Created by Adrián Jaén on 28/11/2021.
//

#ifndef INC_3DBOX_POLYHEDRON_H
#define INC_3DBOX_POLYHEDRON_H

#include "string"
#include "Point3D.h"
#include "Line3D.h"

class Polyhedron {
protected:
    Point3D centerPoint;
public:

    Polyhedron(){
        centerPoint = Point3D();
    }

    virtual Point3D getCenterPoint(){
        return centerPoint;
    }

    virtual bool Intersect(Line3D l, Point3D &coord);
    virtual std::string to_string(){return "";}
};


#endif //INC_3DBOX_POLYHEDRON_H
