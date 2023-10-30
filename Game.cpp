#include <iostream>
#ifdef _WIN32
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif
#include "Enemy.cpp"
#include "Path.h"

using namespace std;

class Game{
	private:
		WINDOW *mainwin;
		Enemy *enemies;
		Path *path;
		
		const int MAX_BUILDINGS = 50;
		const int MAX_ENEMIES = 150;
		int input;
		int pat[4][2] = {{10,10},{40,10},{40,20},{5,20}};  // delete later
	public:
		Game(){								

			enemies = new Enemy[5];		 
			path = new Path(pat);
		}
		
		void ncurses_config(){	
			ncurses_init_colors();
    		keypad(stdscr, TRUE);
    		timeout(500);
    	}
		void init(){
			mainwin = initscr();
			ncurses_config();
		}
	
		void ncurses_init_colors(){
			start_color();
			init_pair(1, COLOR_GREEN, COLOR_BLACK);
			init_pair(2, COLOR_RED, COLOR_BLACK);
		}
	
		void draw(int character){
			clear(); 
			attron(COLOR_PAIR(1));
		
			//prints enemies 
			for(int i = 0; i < 5; i++){
				move(enemies[i].getY(),enemies[i].getX());
				refresh();
				addch(character); 
			}
			attroff(COLOR_PAIR(1)); 
			//prints buildings
			
			attron(COLOR_PAIR(2));
			for(int i = 0; i < 4; i++){
				
				move(path -> getPointY(i),path -> getPointX(i));
				refresh();
				addch('@'); 
			}
			attroff(COLOR_PAIR(2)); 
			move(0,0);	
			refresh();			
	
		}

		void update(){
		
			
			//updates enemies
			for(int i = 0; i < 5; i++){
				enemies[i].move();
			}
			
			//updates buildings
			for(int i = 0; i < 1; i++){
				
			}
		}
		
	
		void game_loop(){
			for(int i = 0; i < 5; i++){
				enemies[i].setX(10); 
				enemies[i].setY(10-i);
				enemies[i].setHealth(200);
				enemies[i].setSpeed(15 + i*150);
				enemies[i].path = path;
			}
			
			while(1){
				napms(50);	 
				update();
				draw('e');
			}
		}
		
		auto end(){
			delwin(mainwin);
			endwin();
			
			refresh();
			return EXIT_SUCCESS;
			
		};
};