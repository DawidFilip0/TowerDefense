#include <iostream>
#ifdef _WIN32
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif
#include <string>
#include <vector>


#include "Building.h"
#include "BldMgr.h"
#include "Enemy.h"
#include "Path.h"
#include "Menu.h"
#include "Wave.h"


using namespace std;

class Game{
	private:
		WINDOW *mainwin;
		Path *path;
		Menu *menu;
		Wave *wave;	
		const int MAX_BUILDINGS = 50;
		const int MAX_ENEMIES = 150;
		int pat[7][2] = {{0,20},{10,20},{10,10},{42,10},{42,20},{65,20},{65,0}};
		int ch;
		MEVENT event;
		BldMgr *buildingManager;		
	public:
		int health = 100;
		int money = 1000;
		Game(){	
		
			path = new Path(pat,7);	
			wave = new Wave(path,&health, &money);			
			buildingManager = new BldMgr(&(path -> pathEdges),wave);	
			menu = new Menu(&health, buildingManager, &money);		
		}
		
		void ncurses_config(){	
			ncurses_init_colors();
			
    		keypad(mainwin, TRUE);
    		nodelay(mainwin, TRUE); 
    		mousemask(ALL_MOUSE_EVENTS, NULL);
			mouseinterval(0);
 
    		timeout(0);
    	}
		
		void init(){
			mainwin = initscr();
			ncurses_config();
		}
	
		void ncurses_init_colors(){
			start_color();
			init_pair(1, COLOR_WHITE, COLOR_BLACK);  //neutral
			init_pair(2, COLOR_BLUE, COLOR_BLACK);   //building
			init_pair(3, COLOR_GREEN, COLOR_BLACK);  //high health
			init_pair(4, COLOR_YELLOW, COLOR_BLACK); //mid health
			init_pair(5, COLOR_RED, COLOR_BLACK);    //low health	
			
		}
	
		void draw(){
			erase(); 
			
			wave -> drawEnemies();
			buildingManager -> drawBuildings();						
			path -> drawPath();	
			menu -> printMenu();
			menu -> showCursor();
									
			move(0,0);	
			refresh();				
		}

		void update(){	
			wave -> update();	
			
			menu -> handleInput(ch);
			buildingManager -> updateBuildings();
		}
			
		void game_loop(){	
				
			wave -> init_wave(8,13);
			
			while(1){
				napms(10);
				ch = getch();	 
				update();
            	draw();
        	}
		}
				
		auto end(){
			delwin(mainwin);
			endwin();
			refresh();
			return EXIT_SUCCESS;			
		};
};