
#include "BldMgr.h"

BldMgr::BldMgr(){
	std::vector<Building> *buildings = new std::vector<Building>;
}

void BldMgr::addBuilding(int x, int y){
	
	buildings -> push_back(Building(x,y));
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