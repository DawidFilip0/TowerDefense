#include <string>
#include "Menu.h"

Menu::Menu(int *playerHealth , BldMgr *buildingManager){
	this -> playerHealth = playerHealth;
	this -> buildingManager = buildingManager;
    options[0][0] = "";
    options[0][1] = "  [1] Building menu";
    options[0][2] = "  [2] Upgrade Menu";
    options[0][3] = "  [3] Options";
    options[0][8] = "  [9] Exit game";
    options[0][9] = "  [Spacebar] to confirm ";
    options[0][10] = "  arrows to move";
    options[1][0] = "";
    options[1][1] = "  [1] Archer Tower";
    options[1][2] = "  [2] Cannon Outpost";
    options[1][8] = "  [9] Go back";
}

void Menu::borderPositions(){
}

string& Menu::getOption(int x, int y){
	return options[x][y];
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
					else{
					    selectedMenuOption = 0;	
					}
                	break;
                case '1':
                	switch(selectedMenuOption){
                		case 0:
                			selectedMenuOption = 1;
                			break;
                		case 1:
                			previewBuilding = true;;
                			selectedMenuOption = 0;
                			break;						
					}
                	
                	break;
                case ' ':
                	
                	if (previewBuilding == true){
                		previewBuilding = false;
                		buildingManager -> addBuilding(cursorX,cursorY);
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
					
					str = getOption(selectedMenuOption,i);

					
					printw(str.c_str());
					
				}
				if(i == 28) {
					attron(COLOR_PAIR(5));
					string h = "        Health: ";
					printw(h.c_str());
				 	printw(to_string(*playerHealth).c_str());
					attroff(COLOR_PAIR(5)); 
				}
			
			}
}