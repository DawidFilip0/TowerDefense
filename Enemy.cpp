#include <string>
#include <chrono>
#include <ctime>
using namespace std::chrono;
using namespace std;

class Enemy {       

		
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> lastCallTime;
	public:
		
	int x;
	int y;
	int health;
	int speed;
	int colour; 
	
	              
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
		
	Enemy(){	}	
	Enemy(int x,int y,int health,int speed, string colour){   //speed is how many milliseconds should pass beetween enemies movements
		this -> x = x;
		this -> y = y;
		this -> health = health;
		this -> speed = speed;
		lastCallTime = std::chrono::high_resolution_clock::now();

		
			
	};
	
};
