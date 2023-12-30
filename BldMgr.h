#pragma once
#include <vector>
#include "Building.h"

class BldMgr{
	private:
		std::vector<Building> *buildings;
	public:
		BldMgr();
		void addBuilding(int x, int y);
		void updateBuildings();
		void drawBuildings();
};		