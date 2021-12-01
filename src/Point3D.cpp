//
// Created by Adrián Jaén on 20/11/2021.

#include "../include/Point3D.h"
#include "cmath"

Point3D::Point3D(float a, float b, float c) {
     p[0]= a, p[1] = b, p[2] = c;
}

/*    Setters/Getters    */

float& Point3D::get(int i) {return p[i];}

float Point3D::getX() const {return p[0];}

float Point3D::getY() const {return p[1];}

float Point3D::getZ() const {return p[2];}

void Point3D::set(float v1, float v2, float v3) {p[0]=v1, p[1]=v2, p[2]=v3;}

void Point3D::setX(float value) {p[0]=value;}

void Point3D::setY(float value) {p[1]=value;}

void Point3D::setZ(float value) {p[2]=value;}

/*      Useful funcs     */

float Point3D::dist(Point3D pt) const {
    return sqrt((p[0] - pt.p[0]) * (p[0] - pt.p[0]) + (p[1] - pt.p[1]) * (p[1] - pt.p[1]) + (p[2] - pt.p[2]) * (p[2] - pt.p[2]));
}

float Point3D::scalarProd(Point3D pt) const {
    return (p[0]*pt.p[0] + p[1]*pt.p[1] + p[2]*pt.p[2]);
}

/*       Operators       */

void Point3D::operator+=(Point3D pt) {
    p[0]+=pt.p[0], p[1]+=pt.p[1], p[2]+=pt.p[2];
}

void Point3D::operator-=(Point3D pt) {
    p[0]-=pt.p[0], p[1]-=pt.p[1], p[2]-=pt.p[2];
}

Point3D Point3D::operator+(Point3D pt) {

    Point3D res(p[0]+pt.p[0], p[1]+pt.p[1], p[2]+pt.p[2]);

    return res;
}

Point3D Point3D::operator-(Point3D pt) {

    Point3D res(p[0]-pt.p[0], p[1]-pt.p[1], p[2]-pt.p[2]);

    return res;
}


float Point3D::operator[](int i) const{
    return p[i];
}

float& Point3D::operator[](int i){
    return p[i];
}







