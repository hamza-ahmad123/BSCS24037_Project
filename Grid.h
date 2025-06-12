#ifndef GRID_H
#define GRID_H

#include "Player.h"
#include "Enemy.h"
#include "Building.h"
#include "HealingPoint.h"

class Grid {
private:
    int width;
    int height;

public:
    Grid();

    Grid(int w, int h);

    void display(Player& p, Enemy* enemies, int e_count, Building* buildings, int b_count, HealingPoint* heals, int h_count);

    bool free_s(int x, int y, Player& p, Enemy* enemies, int e_count);

    void printGrid(Player& player, Enemy* enemies[], int e_count, Building buildings[], int b_count, HealingPoint heals[], int h_count);
};

#endif
