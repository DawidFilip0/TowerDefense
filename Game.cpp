#include <iostream>
#ifdef _WIN32
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif
#include "Enemy.cpp"
#include "Path.cpp"

using namespace std;

class Game{
	private:
		WINDOW *mainwin;
		Enemy *enemies;
		Path *path;
		
		const int MAX_BUILDINGS = 50;
		const int MAX_ENEMIES = 150;
		int input;
		int pat[4][2] = {{10,10},{40,10},{40,20},{5,20}};  // testing variable, delete later
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
				move(enemies[i].y,enemies[i].x);
				refresh();
				addch(character); 
			}
			attroff(COLOR_PAIR(1)); 
			//prints buildings
			
			attron(COLOR_PAIR(2));
			for(int i = 0; i < 4; i++){
				move(path->route[i][1],path->route[i][0]);
				refresh();
				addch('@'); 
			}
			move(0,0);	
			refresh();			
			attroff(COLOR_PAIR(2)); 
	
		}

		void update(int input){
		
			
			//updates enemies
			for(int i = 0; i < 5; i++){
//				switch (input){
//				default:
//					break;
//				case KEY_UP:
//					enemies[i].move(0,-1);
//					break;
//				case KEY_DOWN:
//					enemies[i].move(0,1);
//					break;
//				case KEY_LEFT:
//					enemies[i].move(-1,0);
//					break;
//				case KEY_RIGHT:
//					enemies[i].move(1,0);
//					break;
//			}
				enemies[i].move(1,0);
			}
			
			//updates buildings
			for(int i = 0; i < 1; i++){
				
			}
		}
		
	
		void game_loop(){
			int last_character = 'e';
			for(int i = 0; i < 5; i++){
				enemies[i].x = 10;
				enemies[i].y = 10-i;
				enemies[i].health = 10 + i;
				enemies[i].speed = (150*i) + 200;
				enemies[i].colour = 2;
			}
			
			while(1){
			napms(100);	
//			input = getch();
			input = 1;
//			if(input != ERR)  
			update(input);
			draw(last_character);
			}
		}
		
		auto end(){
			delwin(mainwin);
			endwin();
			refresh();
			return EXIT_SUCCESS;
			
		};
};