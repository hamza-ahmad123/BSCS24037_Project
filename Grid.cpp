#include <iostream>
#include "Grid.h"
using namespace std;

Grid::Grid() {
    width = 10;
    height = 10;
}

Grid::Grid(int w, int h) {
    width = w;
    height = h;
}

bool Grid::free_s(int x, int y, Player& p, Enemy* enemies, int e_count) {
    if (p.x_pos() == x && p.y_pos() == y)
        return false;

    for (int i = 0; i < e_count; i++) {
        if (enemies[i].x_pos() == x && enemies[i].y_pos() == y && enemies[i].isAlive())
            return false;
    }

    return true;
}

void Grid::printGrid(Player& player, Enemy* enemies[], int e_count, Building buildings[], int b_count, HealingPoint heals[], int h_count) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            bool printed = false;

            if (player.x_pos() == i && player.y_pos() == j) {
                cout << "P ";
                printed = true;
            }

            for (int k = 0; k < e_count; k++) {
                if (enemies[k]->isAlive() && enemies[k]->x_pos() == i && enemies[k]->y_pos() == j) {
                    cout << "E ";
                    printed = true;
                    break;
                }
            }

            for (int k = 0; k < b_count; k++) {
                if (buildings[k].x_pos() == i && buildings[k].y_pos() == j) {
                    cout << "B ";
                    printed = true;
                    break;
                }
            }

            for (int k = 0; k < h_count; k++) {
                if (heals[k].x_pos() == i && heals[k].y_pos() == j) {
                    cout << "H ";
                    printed = true;
                    break;
                }
            }

            if (!printed)
                cout << ". ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < e_count; i++) {
        if (enemies[i]->isAlive()) {
            cout << "Enemy " << i + 1 << " HP: " << enemies[i]->current_h() << endl;
        }
    }
}
