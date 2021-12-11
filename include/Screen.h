//
// Created by Adrián Jaén on 19/11/2021.
//

#ifndef SCREEN_H
#define SCREEN_H

#include "Point3D.h"
#include "Vector3D.h"
#include "Line3D.h"
#include "Prism.h"
#include "Sphere.h"
#include "Space.h"

#define DIM 100

class Screen {
private:
    char matrix[DIM][DIM]{};
    Space space;
    Point3D position{0,0,0};
    Vector3D light{0.5,-1,-1};
    float screenLen = 2;
    float rotationY = 0;
    float rotationZ = 0;
public:

    Screen();
    Screen(const Space& space);
    Screen(const Space& space, Point3D);

    void CleanMatrix();
    void setPos(Point3D);

    void updateScreen(Prism);
    void updateScreen(Sphere);
    void updateScreen(Polyhedron *poly);
    void updateScreen();

    void show();

    void applyAngleOrig(Point3D &p) const;
    void applyAnglePos(Point3D &p);
    float getRotationY();

    float getRotationZ();
    void setRotationY(float angle);
    void setRotationZ(float angle);
};

#endif // SCREEN_H
