#include "Projectile.h"


Projectile::Projectile(int x, int y, int dest_x, int dest_y){
	this -> x = x;
	this -> y = y;
	this -> dest_x = dest_x;
	this -> dest_y = dest_y;
	this -> clock = new Clock(150);
};

Projectile::~Projectile(){
	
}

void Projectile::mv(){
	if(!clock -> time_passed()) return;
	
	if(x < dest_x){
		x++;
	}
	else{
		x--;
	}
	if(y < dest_y){
		y++;
	}
	else{
		y--;
	}	
}

void Projectile::draw(){
	move(y,x);
	addch('*');
}

bool Projectile::reached_destination(){
	return (x == dest_x && y == dest_y);
}