#include "include/Screen.h"
#include "include/Prism.h"
#include "iostream"
#include "random"

#define RANGE 20

using namespace std;

/**
 * @brief This fuction creates a random point contained in the prism centered in (0, 0, 0)
 * of size @param size
*/
Point3D randomPoint(int size){
    // random number between 0 and size
    double x = (rand() % size)-size/2.;
    double y = (rand() % size)-size/2.;
    double z = (rand() % size)-size/2.;

    return Point3D(x,y,z);
}

int main() {

    Space space;

    for(int i = 0; i < 3; i++){
        Point3D pt = randomPoint(RANGE);
        Prism p1(pt, pt+Point3D(2,2,2));
        space.addPoly(p1);

        pt = randomPoint(RANGE);
        Prism p2(pt, pt+Point3D(1,1,2));
        space.addPoly(p2);

        pt = randomPoint(RANGE);
        Prism p3(pt, pt+Point3D(3,2,1));
        space.addPoly(p3);

        pt = randomPoint(RANGE);
        Prism p4(pt, pt+Point3D(2,3,4));
        space.addPoly(p4);

        pt = randomPoint(RANGE);
        Sphere s1(pt, 1);
        space.addPoly(s1);

        pt = randomPoint(RANGE);
        Sphere s2(pt, 2);
        space.addPoly(s2);

        pt = randomPoint(RANGE);
        Sphere s3(pt, 3);
        space.addPoly(s3);
    }

    Screen screen(space);
    screen.updateScreen();
    Point3D pos(-10,0,0);

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
            pos.set(-10,0,0);
            screen.setPos(pos);
            screen.setRotationY(0);
            screen.setRotationZ(0);
            screen.updateScreen();
            screen.show();
        }

        // if (option == '8'){
        //     screen.setRotationZ(screen.getRotationZ()+PI/16);
        //     screen.setPos(pos);
        //     screen.updateScreen();
        //     screen.show();
        // }

        // if (option == '2'){
        //     screen.setRotationZ(screen.getRotationZ()-PI/16);
        //     screen.setPos(pos);
        //     screen.updateScreen();
        //     screen.show();
        // }

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
