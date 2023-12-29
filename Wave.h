#pragma once
#include "Enemy.h"
#include <vector>
#include "Path.h"

class Wave {
private:
    int wave_number;
    const int MAX_ENEMIES = 150;
    Path* path;
    int* player_health;

public:
    std::vector<Enemy>* enemies;

    Wave(Path* p, int* player_health);
    int get_wave();
    void update();
    bool detect_end_of_wave();
    void init_wave(int num_of_enemies, int difficulty);
    void set_wave(int n);
};
