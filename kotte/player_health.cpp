#include "player_health.hpp"
//work in progress

void PlayerHealth::take_damage()
{
    if (!dead) {
        health = 0;
        dead = true;
    }
}

bool PlayerHealth::is_dead()
{
    return dead;
}
