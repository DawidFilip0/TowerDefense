#ifdef _WIN32
#include <ncursesw/curses.h>
#else
#include <curses.h>
#endif

#include "Clock.h"


class Projectile{
	private:
		int x;
		int y;
		int dest_x;
		int dest_y;
		Clock* clock;
	public:
		Projectile(int, int, int, int);
		~Projectile();
		void mv();
		void draw();
		bool reached_destination();
};