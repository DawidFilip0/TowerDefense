#ifndef MACHINEGUN_H
#define MACHINEGUN_H

#include "Building.h"

class MachineGun : public Building {
private:


public:
    MachineGun();
    MachineGun(int x, int y, std::vector<Enemy>* enemies, int* money);
    void draw() override; 
};

#endif 
