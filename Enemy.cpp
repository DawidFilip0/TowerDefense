#include <string>
#include <chrono>
#include <ctime>
#include "Menu.h"
#include "Path.h"
using namespace std::chrono;
using namespace std;

class Enemy {       

		
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> lastCallTime;
		int x;
		int y;	
		int health;
		int maxHealth;
		int speed;
		int colour;
		int step = 0;
	public:
		Path* path;
	
	Enemy(){
		this -> x = 10;
		this -> y = 10;
		
		this -> health = 100;
		this -> speed = 1000;
		this -> colour = 1;
		lastCallTime = std::chrono::high_resolution_clock::now();	
		}
			
	Enemy(int x,int y,int maxHealth,int speed, string colour,Path* path){   //speed is how many milliseconds should pass beetween enemies movements
		this -> x = x;
		this -> y = y;
		this -> maxHealth = maxHealth;
		this -> health = this -> maxHealth;
		this -> speed = speed;
		this -> path = path;
		lastCallTime = std::chrono::high_resolution_clock::now();		
	};
	
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
	
	void setX(int sX){
		x = sX;
	}
	
	void setY(int sY){
		y = sY;
	}
	
	int getHealth(){
		return health;
	}
	
	void setHealth(int h){
		health = h;
	}
	
	void setSpeed(int sp){
		speed = sp;
	}
	
	void changeColour(){
		float percent = health;
	}	
	            
	void move(){
			if(can_move()){

				if(path -> getPointX(step) == x && path -> getPointY(step) == y){
					step++;
				}
				if(path -> getPointX(step) > x ){
					x++;
				}
				else if(path -> getPointX(step) < x){
					x--;
				}
				else if(path -> getPointY(step) < y){
					y--;
				}
				else if(path -> getPointY(step) > y){
					y++;
				}
			}
	}
	
	bool can_move(){
		auto currentTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastCallTime);

		if(duration.count() > speed){
				lastCallTime = currentTime;
				return true;
		}
		return false;

	}
	void draw(){
		
	} 		
		

};
