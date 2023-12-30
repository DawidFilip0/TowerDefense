#include "BldMgr.h"
#include <cmath>

BldMgr::BldMgr(std::vector<std::vector<int>> *pathEdges, Wave *wave){
	buildings = new std::vector<Building>;
	this -> pathEdges = pathEdges;
	this -> wave = wave;
}

void BldMgr::addBuilding(int x, int y){	this -> pathEdges = pathEdges;
	for(std::vector<int>& v : *pathEdges){
 		if((x+1 == v[0] && y+1 == v[1] )||(x-1 == v[0] && y-1 == v[1])||(x+1 == v[0] && y-1 == v[1])||(x-1 == v[0] && y+1 == v[1])){
 			return;
		}
	}
	buildings -> push_back(Building(x,y, wave -> enemies));
}

void BldMgr::updateBuildings(){
	
	for (Building& building : *buildings) {
        building.update();
    }
}

void BldMgr::drawBuildings(){
	for (Building& building : *buildings) {
        building.draw();
    }
}