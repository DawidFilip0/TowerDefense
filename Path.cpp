#include "Path.h"

Path::Path(int points[][2]) {
	MAX_TURNS = 20;
    route = new int*[MAX_TURNS];
    for (int i = 0; i < MAX_TURNS; i++) {
        route[i] = new int[2];
        route[i][0] = points[i][0];
        route[i][1] = points[i][1];
    }
}

Path::~Path() {
    for (int i = 0; i < MAX_TURNS; i++) {
        delete[] route[i];
    }
    delete[] route;
}

int Path::getPointX(int s){
	return route[s][0];
}

int Path::getPointY(int s){
	return route[s][1];
}
