#include <string>
#include <chrono>
#include <ctime>
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
	public:
		
	
	Enemy(){
		this -> x = 10;
		this -> y = 10;
		
		this -> health = 100;
		this -> speed = 1000;
		this -> colour = 1;
		lastCallTime = std::chrono::high_resolution_clock::now();	
		}	
	Enemy(int x,int y,int maxHealth,int speed, string colour){   //speed is how many milliseconds should pass beetween enemies movements
		this -> x = x;
		this -> y = y;
		this -> maxHealth = maxHealth;
		this -> health = this -> maxHealth;
		this -> speed = speed;
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
	            
	void move(int x_mv, int y_mv){
			if(can_move()){
				x += x_mv;
				y += y_mv;	
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
