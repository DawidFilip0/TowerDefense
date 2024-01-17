#ifndef CANNONOUTPOST_H
#define CANNONOUTPOST_H

#include "Building.h"

class CannonOutpost : public Building {
private:


public:
    CannonOutpost();
    CannonOutpost(int x, int y, std::vector<Enemy>* enemies, int* money);
    void draw() override; 
};

#endif 
