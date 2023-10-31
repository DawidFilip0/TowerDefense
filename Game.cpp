#include <iostream>
#ifdef _WIN32
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif
#include "Enemy.cpp"
#include "Path.h"
#include "Menu.h"
#include <string>

using namespace std;

class Game{
	private:
		WINDOW *mainwin;
		Enemy *enemies;
		Path *path;
		Menu *menu;
		
		const int MAX_BUILDINGS = 50;
		const int MAX_ENEMIES = 150;
		int pat[4][2] = {{10,10},{40,10},{40,20},{5,20}};  // delete later
	public:
		Game(){								
			
			menu = new Menu;
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


			printw("press x to start");
			getch();
		}
	
		void ncurses_init_colors(){
			start_color();
			init_pair(1, COLOR_WHITE, COLOR_BLACK);  //neutral
			init_pair(2, COLOR_BLUE, COLOR_BLACK);   //building
			init_pair(3, COLOR_GREEN, COLOR_BLACK);  //high health
			init_pair(4, COLOR_YELLOW, COLOR_BLACK); //mid health
			init_pair(5, COLOR_RED, COLOR_BLACK);    //low health
			
			
		}
	
		void draw(int character){
			erase(); 
			
			attron(COLOR_PAIR(3));
			//prints enemies 
			for(int i = 0; i < 5; i++){
				move(enemies[i].getY(),enemies[i].getX());
				addch(character); 
			}
			attroff(COLOR_PAIR(3)); 
			
			//prints buildings
			
			
			//prints path
			attron(COLOR_PAIR(1));
			for(int i = 0; i < 162; i++){
				
				move(path -> pathEdges[i][1],path -> pathEdges[i][0]);
				addch('@'); 
			}
			refresh();
			attroff(COLOR_PAIR(1)); 
			
			//prints menu
			for(int i = 0; i < 30; i++){
				move(i,90);
				addch('|');
				if( i < 9 ){
					
					string& str = menu -> getOption(0,i);

					
					printw(str.c_str());
					
				}
			
			}
			
			
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