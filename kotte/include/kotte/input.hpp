#pragma once

#include <raylib.h>
#include <unordered_map>
#include <vector>

namespace kotte {

    enum class Action {
        Quit,
        Place_bomb,
        Restart,
        Detonate
    };

    enum class Direction {
        Move,
    };

    class Input final {

        struct DirectionBinding {
            std::vector<int> left;
            std::vector<int> right;
            std::vector<int> up;
            std::vector<int> down;
        };

        [[nodiscard]] static bool any_down(const std::vector<int>& keys) noexcept;
        [[nodiscard]] static bool any_pressed(const std::vector<int>& keys) noexcept;

        std::unordered_map<Action, std::vector<int>> actions;
        std::unordered_map<Direction, DirectionBinding> directions;

    public:
        Input() = default;

        void bind(Action action, std::vector<int>keys);
        void bind(Direction direction, std::vector<int> left, 
            std::vector<int> right, std::vector<int> up, std::vector<int> down);

        [[nodiscard]] bool down(Action action) const noexcept;
        [[nodiscard]] bool pressed(Action action) const noexcept;
        [[nodiscard]] Vector2 get(Direction direction) const noexcept;
    };
}


