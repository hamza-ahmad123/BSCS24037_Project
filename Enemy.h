#ifndef ENEMY_H
#define ENEMY_H

#include "Robot.h"
#include "Building.h"
#include "HealingPoint.h"

class Enemy : public Robot {
private:
    int damage;

public:
    Enemy();

    Enemy(int a, int b, int h, int d);

    void moveToward(int target_x, int target_y, Building* buildings, int b_count, HealingPoint* hps, int h_count, Player& player, Enemy** enemies, int e_count);

    bool inRange(int target_x, int target_y);

    int getDamage();

    void display() override;
};

#endif
