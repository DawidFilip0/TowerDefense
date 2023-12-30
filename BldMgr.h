#pragma once
#include <vector>
#include "Building.h"
#include "Wave.h"


class BldMgr{
	private:
		std::vector<Building> *buildings;
		std::vector<std::vector<int>> *pathEdges;
		Wave *wave;
	public:
		BldMgr(std::vector<std::vector<int>> *pathEdges,Wave *wave);
		void addBuilding(int x, int y);
		void updateBuildings();
		void drawBuildings();
};		