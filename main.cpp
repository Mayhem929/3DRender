#include "include/Screen.h"
#include "iostream"

int main() {

    Point3D lb;
    Point3D rt;
    Prism prism;
    Space space;
    Screen screen;

    lb.set(4,1.9,1);
    rt.set(6,3.8,3);
    prism = Prism(lb, rt);
    space.addPrism(prism);

    lb.set(4,-3.8,-1);
    rt.set(6,-2,1);
    prism = Prism(lb, rt);
    space.addPrism(prism);

    lb.set(4.1,1,-3);
    rt.set(5.9,3,-1);
    prism = Prism(lb, rt);
    space.addPrism(prism);

    lb.set(3.1,2,-3);
    rt.set(4.1,3,-2);
    prism = Prism(lb, rt);
    space.addPrism(prism);

    Sphere sphere(Point3D(4,0,0), 1);

    screen.updateScreen(space);
    screen.updateScreen(sphere);
    screen.show();


    bool go_on = true;

    Point3D pos(0,0,0);

    while(go_on){

        char option;
        std::cin >> option;

        if (option == 'a'){
            pos.setY(pos.getY()+1);
            screen.setPos(pos);
            screen.updateScreen(space);
            screen.updateScreen(sphere);
            screen.show();
        }

        if (option == 's'){
            pos.setX(pos.getX()-1);
            screen.setPos(pos);
            screen.updateScreen(space);
            screen.updateScreen(sphere);
            screen.show();
        }

        if (option == 'd'){
            pos.setY(pos.getY()-1);
            screen.setPos(pos);
            screen.updateScreen(space);
            screen.updateScreen(sphere);
            screen.show();
        }

        if (option == 'w'){
            pos.setX(pos.getX()+1);
            screen.setPos(pos);
            screen.updateScreen(space);
            screen.updateScreen(sphere);
            screen.show();
        }

        if (option == 'f'){
            pos.setZ(pos.getZ()+1);
            screen.setPos(pos);
            screen.updateScreen(space);
            screen.updateScreen(sphere);
            screen.show();
        }

        if (option == 'c'){
            pos.setZ(pos.getZ()-1);
            screen.setPos(pos);
            screen.updateScreen(space);
            screen.updateScreen(sphere);
            screen.show();
        }

        if(option == 'q'){
            go_on = false;
        }

    }

    return 0;
}