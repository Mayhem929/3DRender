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
    float screenLen = 2;
public:

    Screen();
    Screen(Space space);
    Screen(Space space, Point3D);

    void CleanMatrix();

    void setPos(Point3D);
    void updateScreen(Prism);
    void updateScreen(Sphere);
    void updateScreen(Space);
    void show();

};

#endif // SCREEN_H
