#include "CannonOutpost.h"

CannonOutpost::CannonOutpost() {

}

CannonOutpost::CannonOutpost(int x, int y, std::vector<Enemy>* enemies, int* money)   : Building(x, y, enemies, money) {
	damage = 95;
	range = 14;
	this -> clock = new Clock(1200);
	*money -= 400;
}

void CannonOutpost::draw() {
		attron(COLOR_PAIR(2));
		for(int i = -1; i<2;i++){
					for(int j = -1; j<2;j++){
						move(y+j,x+i);
						addch('C');
					}
				}
		for (Projectile& projectile : projectiles) {
            projectile.draw();
        }
}
