#pragma once
#include <string>
//#include "Menu.h"
#include "Path.h"
#include "Clock.h"
using namespace std;

class Enemy {
private:
    int x;
    int y;
    int health;
    int maxHealth;
    int speed;
    int step = 0;
    int* player_hp;
    int * money;
    Path* path;
    Clock* clock;

public:
    bool alive = true;

    Enemy();
    Enemy(int x, int y, int maxHealth, int speed,Path* path, int* player_hp, int* money);
    ~Enemy();

    int getX();
    int getY();
    void setX(int sX);
    void setY(int sY);
    int getHealth();
    int getMaxHealth();
    void setHealth(int h);
    void setSpeed(int sp);
    void changeColour();
    void move();
    void update();
    void draw();
};
