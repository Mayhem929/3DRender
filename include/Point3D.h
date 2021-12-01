//
// Created by Adrián Jaén on 20/11/2021.
//

#ifndef POINT3D_H
#define POINT3D_H

#include "Vector3D.h"

class Point3D {
private:
    float p[3] = {0};

public:
    Point3D(){
        p[0] = 0, p[1] = 0, p[2] = 0;
    }

    Point3D(float, float, float);

    float& get(int);
    float getX() const;
    float getY() const;
    float getZ() const;

    void set(float, float, float);
    void setX(float value);
    void setY(float value);
    void setZ(float value);

    float dist(Point3D) const;

    float scalarProd(Point3D) const;

    void operator+=(Point3D pt);
    void operator-=(Point3D pt);

    Point3D operator+(Point3D pt);
    Point3D operator-(Point3D pt);

    float operator[](int i) const;
    float& operator[](int i);
};

#endif //POINT3D_H
