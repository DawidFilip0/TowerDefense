#include "Building.h"
#include <cmath>


Building::Building(int x, int y, std::vector<Enemy> *enemies){
	this -> x = x;
	this ->  y= y;
	this -> clock = new Clock(2000);
	this -> enemies = enemies;
	range = 5;
	
};

Building::Building(){
	x = 10;
	y = 10;
	this -> clock = new Clock(2000);
};

void Building::attack(){
	if(clock -> time_passed()){
		
    	for (Enemy& enemy : *enemies) {
    		
    		if(pow(x - enemy.getX(),2) + pow(y - enemy.getY(),2) <= pow(range,2)){
    			
    			enemy.setHealth(1);
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
		attroff(COLOR_PAIR(2));
			
}

void Building::update(){
	
		attack();
};
