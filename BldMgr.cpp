#include "BldMgr.h"
#include <cmath>

BldMgr::BldMgr(std::vector<std::vector<int>> *pathEdges, Wave *wave, int *money){
	std::vector<Building*> buildings;
	this -> pathEdges = pathEdges;
	this -> wave = wave;
	this -> money = money;
}

void BldMgr::addBuilding(int x, int y,int type){	this -> pathEdges = pathEdges;
	for(std::vector<int>& v : *pathEdges){
 		if((x+1 == v[0] && y+1 == v[1] )||(x-1 == v[0] && y-1 == v[1])||(x+1 == v[0] && y-1 == v[1])||(x-1 == v[0] && y+1 == v[1])){
 			return;
		}
	}
	if(type == 1){
		if(*money >= 100){
			buildings.push_back(new ArcherTower(x,y, wave -> enemies, money));
		}
	}
	else if(type ==2){
		if(*money >= 500){
			buildings.push_back(new CannonOutpost(x,y, wave -> enemies, money));
		}
	}
	else if(type == 3){
		if(*money >= 500){
			buildings.push_back(new MachineGun(x,y, wave -> enemies, money));
		}
	}
}



void BldMgr::updateBuildings(){
	
	for (Building* building : buildings) {
        building -> update();
    }
}

void BldMgr::drawBuildings(){
   for (Building* building : buildings) {
        building->draw(); 
    }
}