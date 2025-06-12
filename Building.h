#ifndef BUILDING_H
#define BUILDING_H

class Building {
private:
    int x;
    int y;
    int s_points;

public:
    Building();

    Building(int a, int b, int s);

    int x_pos();

    int y_pos();

    int getShield();

    void display();
};

#endif
