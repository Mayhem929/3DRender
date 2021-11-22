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

char Prism::HitBoundingBox(float origin[NUMDIM],
                           float dir[NUMDIM],
                           float coord[NUMDIM])
{
    char inside = TRUE;
    char quadrant[NUMDIM];
    int i;
    int whichPlane;
    double maxT[NUMDIM];
    double candidatePlane[NUMDIM];

    /* Find candidate planes; this loop can be avoided if
       rays cast all from the eye(assume perspective view) */
    for (i=0; i<NUMDIM; i++)
        if(origin[i] < minB[i]) {
            quadrant[i] = LEFT;
            candidatePlane[i] = minB[i];
            inside = FALSE;
        }else if (origin[i] > maxB[i]) {
            quadrant[i] = RIGHT;
            candidatePlane[i] = maxB[i];
            inside = FALSE;
        }else	{
            quadrant[i] = MIDDLE;
        }

    /* Ray origin inside bounding box */
    if(inside)	{
        coord = origin;
        return (TRUE);
    }


    /* Calculate T distances to candidate planes */
    for (i = 0; i < NUMDIM; i++)
        if (quadrant[i] != MIDDLE && dir[i] !=0.)
            maxT[i] = (candidatePlane[i]-origin[i]) / dir[i];
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
            coord[i] = origin[i] + maxT[whichPlane] *dir[i];
            if (coord[i] < minB[i] || coord[i] > maxB[i])
                return (FALSE);
        } else {
            coord[i] = candidatePlane[i];
        }
    return (TRUE);				/* ray hits box */
}

char Prism::HitBoundingBox(Point3D origin, Point3D dir, Point3D coord) {
    char inside = TRUE;
    char quadrant[NUMDIM];
    int i;
    int whichPlane;
    float maxT[NUMDIM];
    float candidatePlane[NUMDIM];

    /* Find candidate planes; this loop can be avoided if
       rays cast all from the eye(assume perspective view) */
    for (i=0; i<NUMDIM; i++)
        if(origin[i] < minB[i]) {
            quadrant[i] = LEFT;
            candidatePlane[i] = minB[i];
            inside = FALSE;
        }else if (origin[i] > maxB[i]) {
            quadrant[i] = RIGHT;
            candidatePlane[i] = maxB[i];
            inside = FALSE;
        }else	{
            quadrant[i] = MIDDLE;
        }

    /* Ray origin inside bounding box */
    if(inside)	{
        coord = origin;
        return (TRUE);
    }


    /* Calculate T distances to candidate planes */
    for (i = 0; i < NUMDIM; i++)
        if (quadrant[i] != MIDDLE && dir[i] !=0.)
            maxT[i] = (candidatePlane[i]-origin[i]) / dir[i];
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
            coord.get(i) = origin[i] + maxT[whichPlane] *dir[i];
            if (coord[i] < minB[i] || coord[i] > maxB[i])
                return (FALSE);
        } else {
            coord.get(i) = candidatePlane[i];
        }
    return (TRUE);				/* ray hits box */
}

Point3D& Prism::getLb() {
    return minB;
}

Point3D& Prism::getRt() {
    return maxB;
}
