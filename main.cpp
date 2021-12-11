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

    cout << space.to_string() << endl << endl;
    space.insertionSort(Point3D(5,-5,0));
    cout << space.to_string();

    /*Point3D lb;
    Point3D rt;
    Prism p1;
    Polyhedron * prism = &p1;
    Space space;
    Screen screen;

    lb.set(4,1.9,1);
    rt.set(6,3.8,3);
    p1 = Prism(lb, rt);
    space.addPrism(p1);

    lb.set(4,-3.8,-1);
    rt.set(6,-2,1);
    p1 = Prism(lb, rt);
    space.addPrism(p1);

    lb.set(4.1,1,-3);
    rt.set(5.9,3,-1);
    p1 = Prism(lb, rt);
    space.addPrism(p1);

    lb.set(3.1,2,-3);
    rt.set(4.1,3,-2);
    p1 = Prism(lb, rt);
    space.addPrism(p1);

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

    }*/

    return 0;
}