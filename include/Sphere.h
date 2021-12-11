//
// Created by Adrián Jaén on 23/11/2021.
//

#ifndef INC_3DBOX_SPHERE_H
#define INC_3DBOX_SPHERE_H

#include "Point3D.h"
#include "Vector3D.h"
#include "Line3D.h"
#include "Polyhedron.h"

class Sphere: public Polyhedron {
private:
    Point3D center;
    float radius;
public:

    Sphere();
    Sphere(Point3D, float);

    Point3D& getCenter();
    float& getRadius();

    void setCenter(Point3D);
    void setRadius(float);

    Point3D getCenterPoint() override;
    bool Intersect(Line3D line, Point3D& f_intersect) override;
    std::string to_string() override;
};


#endif //INC_3DBOX_SPHERE_H
