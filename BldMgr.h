#pragma once
#include <vector>
#include "Building.h"


class BldMgr{
	private:
		std::vector<Building> *buildings;
		std::vector<std::vector<int>> *pathEdges;
	public:
		BldMgr(std::vector<std::vector<int>> *pathEdges);
		void addBuilding(int x, int y);
		void updateBuildings();
		void drawBuildings();
};		