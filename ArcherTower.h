#ifndef ARCHERTOWER_H
#define ARCHERTOWER_H

#include "Building.h"

class ArcherTower : public Building {
private:


public:
    ArcherTower();
    ArcherTower(int x, int y, std::vector<Enemy>* enemies, int* money);
    void draw() override; 
};

#endif 
