#include "Game.cpp"
#include "Menu.h"

using namespace std;

int main(void) {
	
	Game game;
	
	game.init();
	game.game_loop();
	return game.end();
}
