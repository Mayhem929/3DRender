//
// Created by Adrián Jaén on 19/11/2021.
//

#include "../include/Screen.h"
#include "iostream"

#ifdef _WIN32
#define COMMAND "CLS"
#endif

#ifdef linux
#define COMMAND "clear"
#endif

using namespace std;

Screen::Screen() {

    for (auto & i : matrix) {
        for (char & j : i) {
            j = '.';
        }
    }
}

void Screen::CleanMatrix(){
    for (auto & i : matrix) {
        for (char & j : i) {
            j = '.';
        }
    }
}

void Screen::show() {

    system(COMMAND);

    string output = "";

    for (int i = DIM-1; i >= 0; --i) {
        for (int j = DIM-1; j >= 0; --j) {
             output+= matrix[i][j];
        }
        output+="\n";
    }

    output += "pos: "+to_string(position[0])+", "+to_string(position[1])+", "+to_string(position[2])+"\n"+
            "rotation: " + to_string(rotationY) + ", " + to_string(rotationZ) + "\n";

    cout << output;


}

void Screen::applyAngle(Point3D &p){
    p.set(position[0] + (p[0]-position[0])*cos(rotationY) - (p[1]-position[1])*sin(rotationY),
          position[1] + (p[0]-position[0])*sin(rotationY) + (p[1]-position[1])*cos(rotationY),
          p[2]);

    p.set(position[0] + (p[0]-position[0])*cos(rotationZ) - (p[2]-position[2])*sin(rotationZ),
          p[1],
          position[2] + (p[0]-position[0])*sin(rotationZ) + (p[2]-position[2])*cos(rotationZ));
}

void Screen::updateScreen(Prism prism) {

    float x0 = position.getX();
    float y0 = position.getY() - screenLen / 2.f;
    float z0 = position.getZ() - screenLen / 2.f;

    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            Point3D screen_point(position.getX() + 1, y0 + screenLen * j / DIM, z0 + screenLen * i / DIM);
            applyAngle(screen_point);
            Line3D line(position, screen_point);
            Point3D coord;

            if (prism.Intersect(line, coord)) {

                // Coloring each face of the prism

                if (coord[0] == prism.getRt().getX())
                    matrix[i][j] = '!';
                else if (coord[1] == prism.getRt().getY())
                    matrix[i][j] = '-';
                else if (coord[2] == prism.getRt().getZ())
                    matrix[i][j] = ':';
                else if (coord[0] == prism.getLb().getX())
                    matrix[i][j] = '*';
                else if (coord[1] == prism.getLb().getY())
                    matrix[i][j] = '/';
                else if (coord[2] == prism.getLb().getZ())
                    matrix[i][j] = '+';
            }
        }
    }
}

void Screen::updateScreen(Sphere sphere) {

    float x0 = position.getX();
    float y0 = position.getY() - screenLen / 2.f;
    float z0 = position.getZ() - screenLen / 2.f;

    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            Line3D line(position, Point3D(position.getX() + 1, y0 + screenLen * j / DIM, z0 + screenLen * i / DIM));
            Vector3D direc = line.getDir();
            float orig[3] = {position[0], position[1], position[2]};
            float dir[3] = {direc.getX(), direc.getY(), direc.getZ()};
            Point3D coord;

            if (sphere.Intersect(line, coord)){
                matrix[i][j] = '*';
            }
        }
    }
}

void Screen::updateScreen(Polyhedron *poly) {

    float x0 = position.getX();
    float y0 = position.getY() - screenLen / 2.f;
    float z0 = position.getZ() - screenLen / 2.f;

    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            Line3D line(position, Point3D(position.getX() + 1, y0 + screenLen * j / DIM, z0 + screenLen * i / DIM));
            Vector3D direc = line.getDir();
            Point3D coord;

            if (poly->Intersect(line, coord)){
                // matrix[i][j] = '*';

                coord-=poly->getCenterPoint();

                Vector3D dir(coord[0], coord[1], coord[2]);

                float angle = dir.angle(light);

                char light_scale[] = {',','-','/','i','o','D','0','*'};

                for(int k = 0; k < 8; ++k){
                    if(angle > (180.f/8) * k && angle <= (180.f/8)*(k+1))
                        matrix[i][j] = light_scale[k];
                }


            }
        }
    }
}


void Screen::setPos(Point3D p) {
    position = p;
}

Screen::Screen(const Space& sp, Point3D pos) {
    space = sp;
    position = pos;
}

Screen::Screen(Space sp) {
    space = sp;
}

/*
void Screen::updateScreen(Space sp) {
    CleanMatrix();
    space = sp;
    for (int i = 0; i < space.getUsed(); ++i) {
        updateScreen(space[i]);
    }
}
*/


float Screen::getRotationY(){
    return rotationY;
}

float Screen::getRotationZ(){
    return rotationZ;
}

void Screen::setRotationY(float angle) {
    rotationY = angle;
}

void Screen::setRotationZ(float angle) {
    rotationZ = angle;
}
