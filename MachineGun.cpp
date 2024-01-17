#include "MachineGun.h"

MachineGun::MachineGun() {

}

MachineGun::MachineGun(int x, int y, std::vector<Enemy>* enemies, int* money)   : Building(x, y, enemies, money) {
	damage = 20;
	range = 10;
	this -> clock = new Clock(180);
	*money -= 400;
}

void MachineGun::draw() {
		attron(COLOR_PAIR(2));
		for(int i = -1; i<2;i++){
					for(int j = -1; j<2;j++){
						move(y+j,x+i);
						addch('M');
					}
				}
		for (Projectile& projectile : projectiles) {
            projectile.draw();
        }
}
