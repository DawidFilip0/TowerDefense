#include <string>
using namespace std;


class Path {
private:
    const int MAX_TURNS = 20; // Maximum number of turns the path will take
    int colour;

public:
	int **route = new int*[MAX_TURNS] ;
    Path(int points[][2]) {
    	for(int i = 0; i < MAX_TURNS; i++){
    		route[i] = new int[2];
		}
    	
        for (int i = 0; i < MAX_TURNS; i++) {
            route[i][0] = points[i][0];
            route[i][1] = points[i][1];
        }
    };
};

