#include "Building.h"


Building::Building(int x, int y){
	this -> x = x;
	this ->  y= y;
	this -> clock = new Clock(100);
	
};

Building::Building(){
	x = 10;
	y = 10;
	this -> clock = new Clock(100);};

void Building::attack(){
	if(clock -> time_passed()){
		
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
			
};
