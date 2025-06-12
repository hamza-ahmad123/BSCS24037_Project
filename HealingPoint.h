#ifndef HEALINGPOINT_H
#define HEALINGPOINT_H

class HealingPoint {
private:
    int x;
    int y;
    int h_points;

public:
    HealingPoint();

    HealingPoint(int a, int b, int h);

    int x_pos();

    int y_pos();

    int getHeal();

    void display();
};

#endif