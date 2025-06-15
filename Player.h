#ifndef PLAYER_H
#define PLAYER_H

#include "Robot.h"
#include "Building.h"
#include "HealingPoint.h"

class Player : public Robot {
private:
    int shield;

public:
    Player();

    Player(int a, int b, int h);

    void move(char d, int gridSize, Robot* enemies[], int e_count, Building* buildings, int b_count, HealingPoint* heals, int h_count);

    void attack(Robot* enemies[], int e_count);

    void takeDamage(int a);

    void heal(int a);

    void addShield(int a);

    void regenerate();

    void display() override;

    int getShield();

    bool isAlive() override;
};

#endif
