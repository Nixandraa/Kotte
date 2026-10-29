#include "player_health.hpp"

void PlayerHealth::count_enemy_kills() noexcept
{
    enemies_killed++;
    if (enemies_killed > 0 && enemies_killed % 2 == 0) {
        shield_timer = 5.0f;
    }
}

void PlayerHealth::set_shield(float delta_time) noexcept
{
    if (shield_timer > 0.0f) {
        shield_timer -= delta_time;
        if (shield_timer < 0.0f) {
            shield_timer = 0.0f;
        }
    }
}

void PlayerHealth::take_damage() noexcept
{
    if (has_shield()) {
        return;
    }
    health = 0;
}

bool PlayerHealth::has_shield() const noexcept
{
    return shield_timer > 0.0f;
}

bool PlayerHealth::is_dead() const noexcept
{
    return health <= 0;
}
