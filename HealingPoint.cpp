#include <iostream>
#include "HealingPoint.h"
using namespace std;

HealingPoint::HealingPoint() {
    x = 0;
    y = 0;
    h_points = 0;
}

HealingPoint::HealingPoint(int a, int b, int h) {
    x = a;
    y = b;
    h_points = h;
}

int HealingPoint::x_pos() {
    return this->x;
}

int HealingPoint::y_pos() {
    return this->y;
}

int HealingPoint::getHeal() {
    return this->h_points;
}

void HealingPoint::display() {
    cout << "You have received " << h_points << " health points!" << endl;
}
