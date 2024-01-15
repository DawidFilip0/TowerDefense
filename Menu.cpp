#include <string>
#include "Menu.h"

Menu::Menu(int *playerHealth , BldMgr *buildingManager, int *money){
	this -> playerHealth = playerHealth;
	this -> buildingManager = buildingManager;
	this -> money = money;
    options[0] = "";
    options[1] = "  [1] Archer Tower";
    options[2] = "  [2] Cannon Outpost";
    options[3] = "  ";
    options[4] = "  ";
    options[5] = "  [Spacebar] to confirm ";
    options[6] = "  arrows to move";
    options[7] = "";
    options[8] = "  ";
    options[9] = "  ";
    options[10] = "  [9] Go back";
}

void Menu::borderPositions(){
}

string& Menu::getOption(int x){
	return options[x];
}

void Menu::handleInput(int ch){
	        if (ch != ERR) {
            switch (ch) {
                case KEY_UP:
                    cursorY--;
                    break;
                case KEY_DOWN:
                    cursorY++;
                    break;
                case KEY_LEFT:
                    cursorX--;
                    break;
                case KEY_RIGHT:
                    cursorX++;
                    break;
                case '9':
                	if(previewBuilding == true){
                		previewBuilding = false;
					}
                	break;
                case '1':
             		previewBuilding = true;;
                	break;											
                case ' ':
                	
                	if (previewBuilding == true){
                		previewBuilding = false;
                		buildingManager -> addBuilding(cursorX,cursorY, 1);
					}
					break;

            }
        }
}

void Menu::showCursor(){
			if(!previewBuilding){
				move(cursorY,cursorX);
				addch('*');
			}
			else{
				attron(COLOR_PAIR(2));
				for(int i = -1; i<2;i++){
					for(int j = -1; j<2;j++){
							move(cursorY+j,cursorX+i);
							addch('#');
					}
				}
				attroff(COLOR_PAIR(2));
			}	
}

void Menu::printMenu(){
	for(int i = 0; i < 30; i++){
				move(i,90);
				addch('|');
				if( i < 11 ){					
					str = getOption(i);					
					printw(str.c_str());					
				}
				if(i == 28) {
					attron(COLOR_PAIR(5));
					string h = "        Health: ";
					printw(h.c_str());
				 	printw(to_string(*playerHealth).c_str());
					attroff(COLOR_PAIR(5)); 
				}
				if(i == 26) {
					attron(COLOR_PAIR(4));
					string h = "        Money: ";
					printw(h.c_str());
				 	printw(to_string(*money).c_str());
					attroff(COLOR_PAIR(4)); 
				}
			
			}
}