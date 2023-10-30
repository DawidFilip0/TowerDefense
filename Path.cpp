#include "Path.h"
#include <vector>

Path::Path(int points[][2]) : pathEdges(3, std::vector<int>(2, 1)) {
	
	half_width = 1;
	MAX_TURNS = 20;
    route = new int*[MAX_TURNS];
    for (int i = 0; i < MAX_TURNS; i++) {
        route[i] = new int[2];
        route[i][0] = points[i][0];
        route[i][1] = points[i][1];
    }
    
    calculatePathEdges();
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

void Path::calculatePathEdges(){
	int dX = 0;
	
	
	for(int i = 1; i < MAX_TURNS; i++){
		dX = (route[i][0] - route[i-1][0]);
		if (dX != 0){
			for(int j = route[i][0]; j > route[i-1][0]; j--){
				
				pathEdges.push_back({j, route[i][1]+half_width});
				pathEdges.push_back({j, route[i][1]-half_width});
			}
		}
		else{
			for(int j = route[i][1]; j > route[i-1][1]; j--){
				pathEdges.push_back({route[i][0]+half_width,j});
				pathEdges.push_back({route[i][0]-half_width,j});
			}
			
		}
	}
	

//	for(int i = 0; i < 16; i++){
//		pathEdges.push_back({i,2*i});
//	}
};
