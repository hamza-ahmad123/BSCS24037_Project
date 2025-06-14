#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Building.h"
#include "HealingPoint.h"
#include "Grid.h"

using namespace std;

const int MAX_ENEMIES = 5;
const int MAX_BUILDINGS = 2;
const int MAX_HEALS = 2;

int main() {
    Player player(0, 0, 100);

    Enemy* e_arr[MAX_ENEMIES];
    e_arr[0] = new Enemy(2, 2, 50, 10);
    e_arr[1] = new Enemy(4, 4, 50, 10);
    e_arr[2] = new Enemy(6, 6, 50, 10);
    e_arr[3] = new Enemy(8, 2, 50, 10);
    e_arr[4] = new Enemy(1, 7, 50, 10);

    Robot* enemies[MAX_ENEMIES];

    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i] = e_arr[i];
    }

    Building buildings[MAX_BUILDINGS] = { Building(3, 3, 20) , Building(6, 3, 20) };

    HealingPoint heals[MAX_HEALS] = { HealingPoint(2, 6, 15) , HealingPoint(5, 5, 15) };

    Grid grid;

    char command;

    while (player.isAlive()) {
        grid.printGrid(player, e_arr, MAX_ENEMIES, buildings, MAX_BUILDINGS, heals, MAX_HEALS);

        cout << endl;

        cout << "Enter move (w/a/s/d): ";
        cin >> command;

        player.move(command, 10, enemies, MAX_ENEMIES, buildings, MAX_BUILDINGS, heals, MAX_HEALS);


        for (int i = 0; i < MAX_HEALS; i++) {
            if (player.x_pos() == heals[i].x_pos() && player.y_pos() == heals[i].y_pos()) {
                player.heal(heals[i].getHeal());
                cout << "Player gained health!\n";
            }
        }


        for (int i = 0; i < MAX_BUILDINGS; i++) {

            if (player.x_pos() == buildings[i].x_pos() && player.y_pos() == buildings[i].y_pos()) {
                player.addShield(buildings[i].getShield());
                cout << "Player gained shield!\n";
            }
        }


        for (int i = 0; i < MAX_ENEMIES; i++) {

            Enemy* e = e_arr[i];

            if (e->isAlive()) {

                e->moveToward(player.x_pos(), player.y_pos(), buildings, MAX_BUILDINGS, heals, MAX_HEALS);

                if (e->inRange(player.x_pos(), player.y_pos())) {
                    player.takeDamage(e->getDamage());
                    cout << "Enemy " << i + 1 << " attacked player!\n";
                }
            }
        }

        player.attack(enemies, MAX_ENEMIES);

        player.regenerate();
    }

    cout << "You lost!\n";

    for (int i = 0; i < MAX_ENEMIES; i++) {
        delete e_arr[i];
    }

}