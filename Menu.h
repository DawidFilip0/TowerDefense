#pragma once
#include <string>

#include <iostream>
#ifdef _WIN32
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif

#include "BldMgr.h"

using namespace std;

class Menu{
	private:
		int	cursorX = 2;
		int cursorY = 2;
		std::string str;
		int *playerHealth;
		int selectedMenuOption = 0;
		bool previewBuilding = false;
		BldMgr *buildingManager;
		int *money; 
		int bType = 0;
		
				
	public:
		
		Menu(int *playerHealth, BldMgr *buildingManager, int *money);
		
		void borderPositions();
		string options[11];
		string& getOption(int x);
		void showCursor();
		void printMenu();
		void handleInput(int ch);

	
	};

