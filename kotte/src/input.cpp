#include "kotte/input.hpp"
#include <raymath.h>
#include <utility>

namespace kotte {

    bool Input::any_down(const std::vector<int>& keys) noexcept
    {
        for (const int key : keys) {
            if (IsKeyDown(key)) {
                return true;
            }
        }
        return false;
    }

    bool Input::any_pressed(const std::vector<int>& keys) noexcept
    {
        for (const int key : keys) {
            if (IsKeyPressed(key)) {
                return true;
            }
        }
        return false;
    }

    void Input::bind(Action action, std::vector<int> keys)
    {
        actions[action] = std::move(keys);
    }

    void Input::bind(Direction direction, std::vector<int> left, std::vector<int> right, 
        std::vector<int> up, std::vector<int> down)
    {
        
        directions[direction] = { std::move(left), std::move(right), std::move(up), std::move(down) };
    }

    bool Input::down(Action action) const noexcept
    {
        const auto it = actions.find(action);
        return it != actions.end() && any_down(it->second);
    }

    bool Input::pressed(Action action) const noexcept
    {
        const auto it = actions.find(action);
        return it != actions.end() && any_pressed(it->second);
    }

    Vector2 Input::get(Direction direction) const noexcept
    {
        const auto it = directions.find(direction);
        if (it == directions.end()) {
            return {};
        }

        const DirectionBinding& binding = it->second;
        Vector2 value{
            float(any_down(binding.right)) - float(any_down(binding.left)),
            float(any_down(binding.down)) - float(any_down(binding.up))
        };
        if (Vector2LengthSqr(value) > 0.0f) {
            value = Vector2Normalize(value);
        }
        return value;
    }
}


