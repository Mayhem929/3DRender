#include "include/Screen.h"
#include "include/Prism.h"
#include "iostream"

using namespace std;

int main() {

    Space space;

    Prism p1(Point3D(4,1.9,1), Point3D(6,3.8,3));
    space.addPoly(p1);

    Prism p2(Point3D(4,-3.8,-1), Point3D(6,-2,1));
    space.addPoly(p2);

    Prism p3(Point3D(4.1,1,-3), Point3D(5.9,3,-1));
    space.addPoly(p3);

    Prism p4(Point3D(3.1,2,-3), Point3D(4.1,3,-2));
    space.addPoly(p4);

    Sphere s1(Point3D(6,0,0), 1);
    space.addPoly(s1);

    Sphere s2(Point3D(5,6,-2), 1.5);
    space.addPoly(s2);

    Sphere s3(Point3D(6,-3, 4),2);
    space.addPoly(s3);

    Screen screen(space);
    screen.updateScreen();
    Point3D pos(0,0,0);

    bool go_on = true;
    while(go_on){

        char option;
        std::cin >> option;

        if (option == 'a'){
            Point3D p(0,1,0);
            screen.applyAngleOrig(p);
            pos = pos+p;
            screen.setPos(pos);
            screen.updateScreen();
        }

        if (option == 's'){
            Point3D p(-1,0,0);
            screen.applyAngleOrig(p);
            pos = pos+p;
            screen.setPos(pos);
            screen.updateScreen();
        }

        if (option == 'd'){
            Point3D p(0,-1,0);
            screen.applyAngleOrig(p);
            pos = pos+p;
            screen.setPos(pos);
            screen.updateScreen();
        }

        if (option == 'w'){
            Point3D p(1,0,0);
            screen.applyAngleOrig(p);
            pos = pos+p;
            screen.setPos(pos);
            screen.updateScreen();
        }

        if (option == 'f'){
            pos.setZ(pos.getZ()+1);
            screen.setPos(pos);
            screen.updateScreen();
        }

        if (option == 'c'){
            pos.setZ(pos.getZ()-1);
            screen.setPos(pos);
            screen.updateScreen();
        }

        if (option == 'r'){
            pos.set(0,0,0);
            screen.setPos(pos);
            screen.setRotationY(0);
            screen.setRotationZ(0);
            screen.updateScreen();
            screen.show();
        }

        if (option == '8'){
            screen.setRotationZ(screen.getRotationZ()+PI/16);
            screen.setPos(pos);
            screen.updateScreen();
            screen.show();
        }

        if (option == '2'){
            screen.setRotationZ(screen.getRotationZ()-PI/16);
            screen.setPos(pos);
            screen.updateScreen();
            screen.show();
        }

        if (option == '4'){
            screen.setRotationY(screen.getRotationY()+PI/16);
            screen.setPos(pos);
            screen.updateScreen();
            screen.show();
        }

        if (option == '6'){
            screen.setRotationY(screen.getRotationY()-PI/16);
            screen.setPos(pos);
            screen.updateScreen();
            screen.show();
        }


        if(option == 'q'){
            go_on = false;
        }

    }

    return 0;
}
