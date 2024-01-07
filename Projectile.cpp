#include "Projectile.h"


Projectile::Projectile(int x, int y, int dest_x, int dest_y){
	this -> x = x;
	this -> y = y;
	this -> dest_x = dest_x;
	this -> dest_y = dest_y;
	this -> clock = new Clock(80);
};

Projectile::~Projectile(){
	
}

void Projectile::mv(){
	if(!clock -> time_passed()) return;
	
	if(x < dest_x){
		x++;
	}
	else if (x > dest_x){
		x--;
	}
	if(y < dest_y){
		y++;
	}
	else if(y > dest_y){
		y--;
	}	
}

void Projectile::draw(){
	attron(COLOR_PAIR(4));
	move(y,x);
	addch('*');
	attron(COLOR_PAIR(2));
}

bool Projectile::reached_destination(){
	return (x == dest_x && y == dest_y);
}