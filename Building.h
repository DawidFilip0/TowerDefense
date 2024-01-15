#ifndef BUILDING_H
#define BUILDING_H

#ifdef _WIN32
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif

#include <string>
#include<vector>

#include "Path.h"
#include "Enemy.h"
#include "Clock.h"
#include "Projectile.h"
#include <algorithm> 


class Menu;

class Building{
protected:
    int damage = 25;
    double attack_speed;
    Clock* clock;
    Projectile* projectile;
    std::vector<Enemy> *enemies;
    std::vector<Projectile> projectiles;
    void update_projectiles();


public:
    int x;
    int y;
    int range;
    int level;
	Building();
    Building(int x, int y, std::vector<Enemy> *enemies,int *money);
    void draw();
    void update();
    void attack();
};

#endif // BUILDING_H
