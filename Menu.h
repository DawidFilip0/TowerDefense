#ifndef Menu_h
#define Menu_h
#include <string>

using namespace std;

class Menu{
	public:
		
		Menu();
		
		void borderPositions();
		string options[2][10];
		string& getOption(int x, int y);
	
	private:
	
	};


#endif