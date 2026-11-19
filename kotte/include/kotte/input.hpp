#pragma once

#include <raylib.h>
#include <unordered_map>

enum class Action {
    Quit,
    Jump,
    Attack,
};

enum class Axis {
    MoveX,
    MoveY,
};

enum class Direction {
    Move,
};

struct InputContext {
    InputContext() = default;

    void bind(Action action, int key);
    void bind(Axis axis, int positive, int negative);
    void bind(Direction direction, int left, int right, int up, int down);

    bool down(Action action) const;
    bool pressed(Action action) const;

    float get(Axis axis) const;
    Vector2 get(Direction direction) const;

private:
    struct AxisBinding {
        int positive;
        int negative;
    };

    struct DirectionBinding {
        int left;
        int right;
        int up;
        int down;
    };

    std::unordered_map<Action, int> actions; //vector of ints
    std::unordered_map<Axis, AxisBinding> axes;
    std::unordered_map<Direction, DirectionBinding> directions;

};

