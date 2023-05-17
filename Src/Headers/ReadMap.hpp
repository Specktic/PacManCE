#pragma once
#include "Pacman.hpp"
#include "Ghost.hpp"

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> read_map(const std::array<std::string, MAP_HEIGHT > &dmap, Pacman &ipac, Ghost &ighost);