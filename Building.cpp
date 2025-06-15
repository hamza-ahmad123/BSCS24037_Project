#include <iostream>
#include "Building.h"
using namespace std;

Building::Building() {
    x = 0;
    y = 0;
    s_points = 0;
}

Building::Building(int a, int b, int s) {
    x = a;
    y = b;
    s_points = s;
}

int Building::x_pos() {
    return this->x;
}

int Building::y_pos() {
    return this->y;
}

int Building::getShield() {
    return this->s_points;
}

void Building::display() {
    cout << "Received " << s_points << " shield points." << endl;
}
