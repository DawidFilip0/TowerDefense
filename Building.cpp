#include "Building.h"
#include <cmath>


Building::Building(int x, int y, std::vector<Enemy> *enemies){
	this -> x = x;
	this -> y = y;
	this -> clock = new Clock(500);
	this -> enemies = enemies;
	range = 15;
//	projectile = new Projectile(0,0,0,0);
	
};

Building::Building(){
	x = 10;
	y = 10;
	this -> clock = new Clock(2000);
//	projectile = new Projectile(0,0,0,0);
};

void Building::attack(){
	if(clock -> time_passed()){
		
    	for (Enemy& enemy : *enemies) {
    		if(!(enemy.alive)){
    			continue;
			}
    		if(pow(x - enemy.getX(),2) + pow(y - enemy.getY(),2) <= pow(range,2)){
    			projectiles.push_back(Projectile(x, y, enemy.getX(), enemy.getY()));
				projectile = new Projectile(x,y,enemy.getX(),enemy.getY());  					
    			enemy.setHealth(enemy.getHealth()-damage);
    			return;
			}
    	}
	}
};

void Building::draw(){
		attron(COLOR_PAIR(2));
		for(int i = -1; i<2;i++){
					for(int j = -1; j<2;j++){
						move(y+j,x+i);
						addch('#');
					}
				}
		for (Projectile& projectile : projectiles) {
            projectile.draw();
        }
		attroff(COLOR_PAIR(2));
			
}

void Building::update(){
	
		attack();
		update_projectiles();		
		
};


void Building::update_projectiles(){
	for (Projectile& projectile : projectiles) {
            projectile.mv();
        }
        
        projectiles.erase(
            std::remove_if(projectiles.begin(), projectiles.end(),
                [](Projectile& projectile) {
                    return projectile.reached_destination();
                }),
            projectiles.end());
}
