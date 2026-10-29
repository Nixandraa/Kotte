#pragma once
#include <cstddef>

//work in progress

class PlayerHealth {
    int health = 1;
    float shield_timer = 0.0f;
    std::size_t enemies_killed = 0;


public:
    void count_enemy_kills() noexcept; // ASSIGNMENT EXTENSION NO. 8  
    void set_shield(float delta_time) noexcept; // ASSIGNMENT EXTENSION NO. 8  
    void take_damage() noexcept;
    bool is_dead() const noexcept;
    bool has_shield() const noexcept; // ASSIGNMENT EXTENSION NO. 8  
};
