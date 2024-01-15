#include "Archer_Tower.h"

ArcherTower::ArcherTower() {
    // Default constructor
}

ArcherTower::ArcherTower(int x, int y, std::vector<Enemy>* enemies, int* money)   : Building(x, y, enemies, money) {
	damage = 25;
	range = 12;
	this -> clock = new Clock(200);
}

void ArcherTower::draw() {
		attron(COLOR_PAIR(2));
		for(int i = -1; i<2;i++){
					for(int j = -1; j<2;j++){
						move(y+j,x+i);
						addch('A');
					}
				}
		for (Projectile& projectile : projectiles) {
            projectile.draw();
        }
}
