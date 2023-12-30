#include "Path.h"
#include <vector>

Path::Path(int points[][2],int number_of_turns) {
	
	half_width = 1;
	MAX_TURNS = 25;
	this -> pathEdges = std::vector<std::vector<int>>(0, std::vector<int>(2, 1));
	no_turns = number_of_turns;
    route = new int*[MAX_TURNS];
    for (int i = 0; i < no_turns; i++) {
        route[i] = new int[2];
        route[i][0] = points[i][0];
        route[i][1] = points[i][1];
    }
       for (int i = no_turns; i < MAX_TURNS; i++) {
        route[i] = new int[2];
        route[i][0] = 0;
        route[i][1] = 0;
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

void Path::drawPath(){
		attron(COLOR_PAIR(1));		
			for(std::vector<int> v : pathEdges){
				move(v[1],v[0]);
				addch('@'); 
			}
			refresh();
		attroff(COLOR_PAIR(1));
}

void Path::calculatePathEdges(){
	int dX = 0;
	int dY = 0;
	
	for(int i = 1; i < this -> no_turns; i++){  
		dX = (route[i][0] - route[i-1][0]);
		dY = (route[i][1] - route[i-1][1]);
		if (dX > 0){
			for(int j = route[i][0]-1; j > route[i-1][0]; j--){
				
				pathEdges.push_back({j, route[i][1]+half_width});
				pathEdges.push_back({j, route[i][1]-half_width});
			}
			pathEdges.push_back({route[i][0]+1, route[i][1]});
			pathEdges.push_back({route[i-1][0]-1, route[i-1][1]});
		}
		else if (dX < 0){
			for(int j = route[i][0]+1; j < route[i-1][0]; j++){
				
				pathEdges.push_back({j, route[i][1]+half_width});
				pathEdges.push_back({j, route[i][1]-half_width});
			}
			pathEdges.push_back({route[i][0]-1, route[i][1]});
			pathEdges.push_back({route[i-1][0]+1, route[i-1][1]});
		}	
		else if (dY > 0){
			for(int j = route[i][1]-1; j > route[i-1][1]; j--){
				pathEdges.push_back({route[i][0]+half_width,j});
				pathEdges.push_back({route[i][0]-half_width,j});
			}
			pathEdges.push_back({route[i][0], route[i][1]+1});
			pathEdges.push_back({route[i-1][0], route[i-1][1]-1});
			
		}
		else if (dY < 0){
			for(int j = route[i][1]+1; j < route[i-1][1]; j++){
				pathEdges.push_back({route[i][0]+half_width,j});
				pathEdges.push_back({route[i][0]-half_width,j});
			}
			pathEdges.push_back({route[i][0], route[i][1]-1});
			pathEdges.push_back({route[i-1][0], route[i-1][1]+1});
			
		}
		
	}

};
