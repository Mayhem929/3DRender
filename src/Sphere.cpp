//
// Created by Adrián Jaén on 23/11/2021.
//

#include "../include/Sphere.h"


Sphere::Sphere() {
    center = Point3D(0,0,0);
    radius = 0;
}

Sphere::Sphere(Point3D c, float r) {
    center = c;
    radius = r;
}

Point3D &Sphere::getCenter() {
    return center;
}

float &Sphere::getRadius() {
    return radius;
}

void Sphere::setCenter(Point3D c) {
    center = c;
}

void Sphere::setRadius(float r) {
    radius = r;
}


template <class T> float mod_squared(T d){
    return (d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);
}

Point3D Sphere::getCenterPoint() {
    return center;
}

bool Sphere::Intersect(Line3D line, Point3D& f_intersect) {

    double A = 0, B = 0, C = 0;

    Point3D orig = line.getOrig();
    Vector3D dir = line.getDir();


    A = mod_squared(dir);
    B = 2 * dir[0] * (orig[0] - center[0]) +
        2 * dir[1] * (orig[1] - center[1]) +
        2 * dir[2] * (orig[2] - center[2]) ;
    C = mod_squared(center) + mod_squared(orig)
        -2*(orig[0] * center[0] + orig[1] * center[1] + orig[2] * center[2])
        -radius * radius;

    double discriminant = B*B-4*A*C;

    if(discriminant < 0)
        return false;

    double result1 = (-B + sqrt(discriminant))/(2*A);
    double result2 = (-B - sqrt(discriminant))/(2*A);

    Vector3D v_aux;

    if (result1 > 0 && result2 < 0)
        v_aux = dir * float(result1);
    else
        v_aux = dir * float(result2);

    if (result1 <= 0 && result2 <= 0)
        return false;


    Point3D first_intersect(v_aux.getX(),v_aux.getY(),v_aux.getZ());
    first_intersect += orig;

    f_intersect = first_intersect;

    return true;
}

std::string Sphere::to_string() {
    std::string out = "";
    out += "Sphere: " + center.to_string() + "\n"
           + "Radius: " + std::to_string(radius);
    return out;
}
