#pragma once
#include <vector>
#include "Building.h"
#include "Wave.h"
#include "ArcherTower.h"
#include "CannonOutpost.h"
#include "MachineGun.h"


class BldMgr{
	private:
		int *money;
		std::vector<Building*> buildings;
		std::vector<std::vector<int>> *pathEdges;
		Wave *wave;
	public:
		BldMgr(std::vector<std::vector<int>> *pathEdges,Wave *wave, int *money);
		void addBuilding(int x, int y,int type);
		void updateBuildings();
		void drawBuildings();
};		