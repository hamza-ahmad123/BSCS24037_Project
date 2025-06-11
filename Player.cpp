#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() {
    x = 0;
    y = 0;
    health = 100;
    shield = 0;
}

Player::Player(int a, int b, int h) {
    x = a;
    y = b;
    health = h;
    shield = 0;
}

void Player::move(char d, int gridSize, Robot* enemies[], int e_count, Building* buildings, int b_count, HealingPoint* heals, int h_count) {
    int xx = x;
    int yy = y;

    if (d == 'w') xx--;
    else if (d == 's') xx++;
    else if (d == 'a') yy--;
    else if (d == 'd') yy++;


    if (xx < 0 || xx >= gridSize || yy < 0 || yy >= gridSize) {
        cout << "Press valid move!" << endl;
        return;
    }

    for (int i = 0; i < e_count; i++) {
        if (enemies[i] && enemies[i]->isAlive() && enemies[i]->x_pos() == xx && enemies[i]->y_pos() == yy) {
            //cout << "Enemy is already there!\n";
            return;
        }
    }

    x = xx;
    y = yy;

    for (int i = 0; i < b_count; i++) {
        if (buildings[i].x_pos() == x && buildings[i].y_pos() == y) {
            cout << "You have entered a building!" << endl;
            addShield(buildings[i].getShield());
        }
    }

    for (int i = 0; i < h_count; i++) {
        if (heals[i].x_pos() == x && heals[i].y_pos() == y) {
            cout << "You have gained healing points!" << endl;
            heal(heals[i].getHeal());
        }
    }
}

void Player::attack(Robot* enemies[], int e_count) {
    for (int i = 0; i < e_count; i++) {
        if (enemies[i] && enemies[i]->isAlive()) {
            int ex = enemies[i]->x_pos();
            int ey = enemies[i]->y_pos();

            int dx = x - ex;
            int dy = y - ey;

            if (dx * dx + dy * dy <= 1) {
                enemies[i]->takeDamage(20);
                cout << "You attacked enemy at (" << ex << ", " << ey << ")!" << endl;
            }
        }
    }
}

void Player::takeDamage(int a) {

    if (shield >= a) {
        shield = shield - a;
    }

    else {

        int remaining = a - shield;

        shield = 0;

        health = health - remaining;

        if (health < 0) {
            health = 0;
        }
    }
}


void Player::heal(int a) {

    health = health + a;

    if (health > 100) {
        health = 100;
    }
}

void Player::addShield(int a) {

    shield = shield + a;

    if (shield > 50) {
        shield = 50;
    }
}

void Player::regenerate() {

    if (health < 100) {
        health = health + 1;
    }
}


void Player::display() {
    cout << "Player Position: (" << x << ", " << y << ") , ";
    cout << "Health: " << health << " , Shield: " << shield << endl;
}

int Player::getShield() {

    return this->shield;
}
