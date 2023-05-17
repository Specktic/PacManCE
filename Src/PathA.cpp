#include <cmath>

#include "Headers/Globals.hpp"
#include "Headers/PathA.hpp"
#include "Headers/Ghost.hpp"
#include "Headers/Pacman.hpp"

float calc_h(Position start, Position end)
{
    float manhattan_x = end.x - start.x;
    float manhattan_y = end.y - start.y;

    return static_cast<float>(abs(manhattan_x + manhattan_y));
}

