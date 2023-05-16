#pragma once

#include "Pacman.hpp"

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> read_map(const std::array<std::string, MAP_HEIGHT > &dmap, Pacman &ipac);