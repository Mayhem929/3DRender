//
// Created by Adrián Jaén on 21/11/2021.
//

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3D.h"
#include "cmath"

class Vector3D {
private:
    float x;
    float y;
    float z;

public:

    float getX() const;
    float getY() const;
    float getZ() const;

    void set(Vector3D p);
    void setX(float);
    void setY(float);
    void setZ(float);

    Vector3D();
    Vector3D(float, float, float);
    void normalize();
    void ridZeros();
};


#endif //VECTOR3D_H
