#include "Game.cpp"

using namespace std;



int main(void) {
	Game game;
	game.init();
	int i = 0;
	game.game_loop();
	return game.end();


}
