//
// Created by Adrián Jaén on 21/11/2021.
//

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3D.h"
#include "cmath"

class Vector3D {
private:
    float v[3]{};

public:

    Vector3D();
    Vector3D(Point3D p);
    Vector3D(float, float, float);

    float getX() const;
    float getY() const;
    float getZ() const;

    void set(Vector3D p);

    void setX(float);
    void setY(float);
    void setZ(float);

    void normalize();
    void ridZeros();
    float scalarProd(Vector3D vec);
    float length();
    float angle(Vector3D vec);

    float& operator[](int i);
    Vector3D operator*(float num);
    Vector3D& operator*=(float num);
};


#endif //VECTOR3D_H
