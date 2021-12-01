//
// Created by Adrián Jaén on 21/11/2021.
//

#include "../include/Vector3D.h"
#include "cfloat"

float Vector3D::getX() const {return v[0];}

float Vector3D::getY() const {return v[1];}

float Vector3D::getZ() const {return v[2];}

void Vector3D::set(Vector3D vec) {
    v[0]=vec[0];
    v[1]=vec[1];
    v[2]=vec[2];

    normalize();
}

void Vector3D::setX(float value) {v[0]=value;}

void Vector3D::setY(float value) {v[1]=value;}

void Vector3D::setZ(float value) {v[2]=value;}

Vector3D::Vector3D() {
    v[0]=0, v[1]=0, v[2]=0;
}

Vector3D::Vector3D(Point3D p) {
    v[0]=p[0], v[1]=p[1], v[2]=p[2];
}

Vector3D::Vector3D(float a, float b, float c) {
    v[0] = a, v[1] = b, v[2] = c;
}

void Vector3D::normalize() {
    double mod = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    mod = round(mod * 10000.0) / 10000.0;
    v[0]/=mod, v[1]/=mod, v[2]/=mod;
}

void Vector3D::ridZeros() {
    for(int i = 0; i<3; ++i)
        if(v[0] == 0){v[0] = FLT_MIN;}
}

float &Vector3D::operator[](int i) {
    return v[i];
}

Vector3D Vector3D::operator*(float num) {
    Vector3D res;

    for (int i = 0; i < 3; ++i) {
        res[i] = v[i]*num;
    }

    return res;
}

Vector3D &Vector3D::operator*=(float num) {

    for (float & i : v) {
        i = i*num;
    }

    return *this;
}

float Vector3D::scalarProd(Vector3D vec) {
    return (v[0]*vec[0]+v[1]*vec[1]+v[2]*vec[2]);
}

float Vector3D::length() {
    return (std::sqrt(scalarProd(*this)));
}

float Vector3D::angle(Vector3D vec) {
    return std::acos( (scalarProd(vec)) / length()*vec.length());
}


