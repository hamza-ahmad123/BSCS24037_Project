#ifndef ROBOT_H
#define ROBOT_H

class Robot {
protected:
    int x;
    int y;
    int health;

public:

    Robot();

    Robot(int a, int b, int h);

    int x_pos();

    int y_pos();

    int current_h();

    void setPosition(int a, int b);

    virtual void takeDamage(int a);

    virtual void display();

    virtual bool isAlive();
};

#endif
