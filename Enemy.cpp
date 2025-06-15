#include <iostream>
#include "Enemy.h"
#include "Building.h"
#include "HealingPoint.h"
#include "Player.h"
using namespace std;

Enemy::Enemy() {
    x = 0;
    y = 0;
    health = 50;
    damage = 10;
}

Enemy::Enemy(int a, int b, int h, int d) {
    x = a;
    y = b;
    health = h;
    damage = d;
}

void Enemy::moveToward(int target_x, int target_y, Building* buildings, int b_count, HealingPoint* hps, int h_count, Player& player, Enemy** enemies, int e_count) {
    int _x = x;
    int _y = y;

    if (x < target_x) {
        _x++;
    }
    else if (x > target_x) {
        _x--;
    }

    else if (y < target_y) {
        _y++;
    }
    else if (y > target_y) {
        _y--;
    }

    for (int i = 0; i < b_count; i++) {
        if (buildings[i].x_pos() == _x && buildings[i].y_pos() == _y) {
            return;
        }
    }

    for (int i = 0; i < h_count; i++) {
        if (hps[i].x_pos() == _x && hps[i].y_pos() == _y) {
            return;
        }
    }

    if (player.x_pos() == _x && player.y_pos() == _y) {
        return;
    }

    for (int i = 0; i < e_count; i++) {
        if (enemies[i] != this && enemies[i]->x_pos() == _x && enemies[i]->y_pos() == _y) {
            return;
        }
    }

    x = _x;
    y = _y;
}

bool Enemy::inRange(int target_x, int target_y) {
    int dx = x - target_x;
    int dy = y - target_y;

    int value = dx * dx + dy * dy;
    bool rn = (value <= 1);

    return rn;
}

int Enemy::getDamage() {
    return this->damage;
}

void Enemy::display() {
    cout << "Enemy at (" << x << ", " << y << ") , ";
    cout << "  Health: " << health << " , Damage: " << damage << endl;
}
