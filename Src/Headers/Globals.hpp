#pragma once

//Ghosts moving speed
constexpr unsigned char GHOST_SPEED = 1;

//Pacman moving speed
constexpr unsigned char PAC_SPEED = 2;

//Map height
constexpr unsigned char MAP_HEIGHT = 21;

//Map width
constexpr unsigned char MAP_WIDTH = 21;

//Resize value
constexpr unsigned char SCREEN_RESIZE = 2;

//Cell size
constexpr unsigned char CELL_SIZE = 16;

//Lettering size
constexpr unsigned char FONT_HEIGHT = 16;

//Frame time
constexpr unsigned short FRAME_DURATION = 20000;

//Non-entity cell types
enum Cell
{
	Empty,
	Point,
	Wall,
	PowerUp,
};

//Entity position
struct Position
{
	short x;
	short y;

	bool operator == (const Position& i_position)
	{
		return this->x == i_position.x && this->y == i_position.y;
	}
};

