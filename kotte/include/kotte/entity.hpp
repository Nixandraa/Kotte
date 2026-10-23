#pragma once

#include "kotte/entity_handle.hpp"
#include "../player_health.hpp"

#include <cstdint>
#include <optional>
#include <raylib.h>

namespace kotte
{
    enum class EntityKind : std::uint8_t {
        player,
        bomb,
        crate,
        enemy
    };

    enum class CardinalDirection : std::uint8_t {
        up,
        right,
        down,
        left
    };

    struct BombState final {
        EntityHandle owner;
        float fuse_remaining = 0.0f;
        std::uint8_t blast_range = 0;
        bool detonation_requested = false;
        bool is_available = false; // ASSIGNMENT EXTENSION NO. 6 !!!
    };

    struct Entity final {
        EntityKind kind = EntityKind::crate;
        Vector2 world_position{};
        CardinalDirection movement_heading = CardinalDirection::right;
        std::optional<BombState> bomb_state;
        std::optional<PlayerHealth> player_health; // ASSIGNMENT REQUIRED FEATURES NO. 1
    };

}
