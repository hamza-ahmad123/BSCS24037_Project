#include <iostream>
#include "Robot.h"
using namespace std;

Robot::Robot() {
    x = 0;
    y = 0;
    health = 100;
}

Robot::Robot(int a, int b, int h) {
    x = a;
    y = b;
    health = h;
}

int Robot::x_pos() {
    return this->x;
}

int Robot::y_pos() {
    return this->y;
}


int Robot::current_h() {
    return this->health;
}


void Robot::setPosition(int a, int b) {
    x = a;
    y = b;
}

void Robot::takeDamage(int a) {
    health = health - a;
    if (health < 0) {
        health = 0;
    }
}

void Robot::display() {
    cout << "Position: (" << x << " , " << y << ") , ";
    cout << "Health: " << health << endl;
}

bool Robot::isAlive() {

    if (health > 0) {
        return true;
    }

    return false;
}
