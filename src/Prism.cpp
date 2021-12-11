//
// Created by Adrián Jaén on 21/11/2021.
//

#include "../include/Prism.h"

Prism::Prism() {
    Point3D p;
    minB = maxB = p;
}

Prism::Prism(Point3D left_bottom, Point3D right_top){
    minB = left_bottom, maxB = right_top;
}

bool Prism::Intersect(Line3D l, Point3D &coord){
    char inside = TRUE;
    char quadrant[NUMDIM];
    int i;
    int whichPlane;
    double maxT[NUMDIM];
    double candidatePlane[NUMDIM];

    /* Find candidate planes; this loop can be avoided if
       rays cast all from the eye(assume perspective view) */
    for (i=0; i<NUMDIM; i++)
        if(l.getOrig()[i] < minB[i]) {
            quadrant[i] = LEFT;
            candidatePlane[i] = minB[i];
            inside = FALSE;
        }else if (l.getOrig()[i] > maxB[i]) {
            quadrant[i] = RIGHT;
            candidatePlane[i] = maxB[i];
            inside = FALSE;
        }else	{
            quadrant[i] = MIDDLE;
        }

    /* Ray origin inside bounding box */
    if(inside)	{
        coord = l.getOrig();
        return (TRUE);
    }

    /* Calculate T distances to candidate planes */
    for (i = 0; i < NUMDIM; i++)
        if (quadrant[i] != MIDDLE && l.getDir()[i] !=0.)
            maxT[i] = (candidatePlane[i]-l.getOrig()[i]) / l.getDir()[i];
        else
            maxT[i] = -1.;

    /* Get largest of the maxT's for final choice of intersection */
    whichPlane = 0;
    for (i = 1; i < NUMDIM; i++)
        if (maxT[whichPlane] < maxT[i])
            whichPlane = i;

    /* Check final candidate actually inside box */
    if (maxT[whichPlane] < 0.) return (FALSE);
    for (i = 0; i < NUMDIM; i++)
        if (whichPlane != i) {
            coord[i] = l.getOrig()[i] + maxT[whichPlane] *l.getDir()[i];
            if (coord[i] < minB[i] || coord[i] > maxB[i])
                return (FALSE);
        } else {
            coord[i] = candidatePlane[i];
        }
    return (TRUE);				/* ray hits box */
}

Point3D& Prism::getLb() {
    return minB;
}

Point3D& Prism::getRt() {
    return maxB;
}

Point3D Prism::getCenterPoint() {
    auto out = (minB + maxB) * (1 / 2.);
    return out;
}

std::string Prism::to_string() {
    std::string out = "";
    out += "Cube: " + minB.to_string() + ", " +maxB.to_string() + "\n"
            + "Midpoint: " + getCenterPoint().to_string();
    return out;
}
