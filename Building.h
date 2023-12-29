#ifndef BUILDING_H
#define BUILDING_H

#ifdef _WIN32
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif

#include<vector>
#include "Path.h"
#include <string>
#include "Enemy.h"
#include "Clock.h"

class Menu;

class Building{
private:
    int damage;
    double attack_speed;
    Clock* clock;

public:
    int x;
    int y;
    int range;
    int level;
	Building();
    Building(int x, int y);
    void draw();
    void update();
    void attack();
};

#endif // BUILDING_H
