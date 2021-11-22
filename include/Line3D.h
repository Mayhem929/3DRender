//
// Created by Adrián Jaén on 20/11/2021.
//

#ifndef LINE3D_H
#define LINE3D_H

#include "Point3D.h"
#include "Vector3D.h"

class Line3D {
private:
    Point3D orig;
    Vector3D dir;

public:
    Line3D();

    Line3D(Point3D, Point3D);

    Point3D& getOrig();
    Vector3D& getDir();

    void setOrig(Point3D point);
    void setDir(Point3D);

    bool contains(Point3D);
};


#endif //LINE3D_H
