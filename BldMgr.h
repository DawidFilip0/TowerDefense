#pragma once
#include <vector>
#include "Building.h"

class BldMgr{
	private:
		std::vector<Building> *buildings;
	public:
		BldMgr();
		void addBuilding();
		void updateBuildings();
};