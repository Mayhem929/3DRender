//
// Created by Adrián Jaén on 20/11/2021.
//

#ifndef SPACE_H
#define SPACE_H

#include "Prism.h"

class Space {
private:
    Prism prisms[10];
    int used;
public:
    Space();
    Space(Prism);

    Prism getPrism(int);
    int getUsed();
    void setPrism(Prism, int);
    void addPrism(Prism);

    Prism& operator[](int);
};


#endif // SPACE_H
