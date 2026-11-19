#include "kotte/input.hpp"
#include <raymath.h>

void InputContext::bind(Action action, int key)
{
    actions[action] = key; //in case of vector pushback key
}

void InputContext::bind(Axis axis, int positive, int negative)
{
    axes[axis] = AxisBinding{ positive, negative };
}

void InputContext::bind(Direction direction, int left, int right, int up, int down)
{
    directions[direction] = DirectionBinding{
        .left = left,
        .right = right,
        .up = up,
        .down = down,
    };
}

bool InputContext::down(Action action) const
{
    auto it = actions.find(action);
    return it != actions.end() && IsKeyDown(it->second); //second is a bound key
}

bool InputContext::pressed(Action action) const
{
    auto it = actions.find(action);
    return it != actions.end() && IsKeyPressed(it->second);
}

float InputContext::get(Axis axis) const
{
    auto it = axes.find(axis);
    if (it == axes.end()) {
        return 0.0f;
    }

    const auto& b = it->second;
    float value = float(IsKeyDown(b.positive)) - float(IsKeyDown(b.negative));
    return value;
}

Vector2 InputContext::get(Direction direction) const
{
    auto it = directions.find(direction);
    if (it == directions.end()) {
        return {0.0f, 0.0f};
    }

    const auto& b = it->second;
    Vector2 value{
        .x = float(IsKeyDown(b.right)) - float(IsKeyDown(b.left)),
        .y = float(IsKeyDown(b.down)) - float(IsKeyDown(b.up)),
    };

    if (Vector2LengthSqr(value) > 0.0f) {
        value = Vector2Normalize(value); //length of it is 1
    }

    return value;
}
