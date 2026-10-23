#pragma once
#include <vector>

//work in progress

class PlayerHealth {
    int health = 1;
    bool dead = false;


public:
    void take_damage();
    bool is_dead();
};
