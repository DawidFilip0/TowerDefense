#include <string>
#include <iostream>
#include "Menu.h"
#include <string>


using namespace std;
Menu::Menu(){
    options[0][0] = "";
    options[0][1] = "  [1] Building menu";
    options[0][2] = "  [2] Upgrade Menu";
    options[0][3] = "  [3] Options";
    options[0][8] = "  [9] Exit game";
    options[1][0] = "";
    options[1][1] = "  [1] Archer Tower";
    options[1][2] = "  [2] Cannon outpost";
    options[1][8] = "  [9] Go back";
}

void Menu::borderPositions(){
}

string& Menu::getOption(int x, int y){
	return options[x][y];
}