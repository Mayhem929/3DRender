//
// Created by Adrián Jaén on 20/11/2021.
//

#include "../include/Space.h"

Space::Space() {
    used = 0;
}

Space::Space(Prism prism) {
    prisms[0] = prism;
    used = 1;
}

Prism Space::getPrism(int i) {
    return prisms[i];
}

int Space::getUsed(){
    return used;
};

void Space::setPrism(Prism prism, int i) {
    prisms[i] = prism;
}

void Space::addPrism(Prism prism) {
    prisms[used] = prism;
    ++used;
}

Prism& Space::operator[](int i) {
    return prisms[i];
}
