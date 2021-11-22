//
// Created by Adrián Jaén on 20/11/2021.
//

#include "../include/Line3D.h"
#include "cmath"

Line3D::Line3D() {
    orig=Point3D();
}

Line3D::Line3D(Point3D point1, Point3D point2) {
    point2-=point1;

    setOrig(point1);
    setDir(point2);
}

Point3D& Line3D::getOrig() {return orig;}

Vector3D& Line3D::getDir() {return dir;}

void Line3D::setOrig(Point3D point) {orig = point;}

void Line3D::setDir(Point3D point) {
    dir.set(Vector3D(point.getX(), point.getY(), point.getZ()));
}

bool Line3D::contains(Point3D p3) {

    p3 -= orig;

    double r1 = 0, r2 = 0, r3 = 0;
    if(dir.getX() == 0 && dir.getY() == 0)
        return p3.getX() == 0 && p3.getY() == 0;
    if(dir.getX() == 0 && dir.getZ() == 0)
        return p3.getX() == 0 && p3.getZ() == 0;
    if(dir.getY() == 0 && dir.getZ() == 0)
        return p3.getY() == 0 && p3.getZ() == 0;

    if(dir.getX() != 0)
        r1 = round((p3.getX()/dir.getX())*10000);
    if(dir.getY() != 0)
        r2 = round((p3.getY()/dir.getY())*10000);
    if(dir.getZ() != 0)
        r3 = round((p3.getZ()/dir.getZ())*10000);

    if(dir.getX() == 0)
        return r2 == r3 && p3.getX() == 0;
    if(dir.getY() == 0)
        return r1 == r3 && p3.getY() == 0;
    if(dir.getZ() == 0)
        return r1 == r2 && p3.getZ() == 0;

    bool contained = (r1 == r2 && r2 == r3);


    return contained;

}