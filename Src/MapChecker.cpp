#include <array>
#include <cmath>
#include <iostream>

#include "Headers/Globals.hpp"
#include "Headers/MapChecker.hpp"

bool map_check(bool ipoint, short ix, short iy, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &imap)
{
    bool output = 0;

    float cell_x = ix / static_cast<float>(CELL_SIZE);
	float cell_y = iy / static_cast<float>(CELL_SIZE);

    for (unsigned char a = 0; a < 4; a++)
	{
		short x = 0;
		short y = 0;

		switch (a)
		{
            //Top left cell
			case 0: 
			{
				x = static_cast<short>(floor(cell_x));
				y = static_cast<short>(floor(cell_y));

				break;
			}

            //Top right cell
			case 1: 
			{
				x = static_cast<short>(ceil(cell_x));
				y = static_cast<short>(floor(cell_y));

				break;
			}

            //Bottom left cell
			case 2: 
			{
				x = static_cast<short>(floor(cell_x));
				y = static_cast<short>(ceil(cell_y));

				break;
			}

            //Bottom right cell
			case 3: 
			{
				x = static_cast<short>(ceil(cell_x));
				y = static_cast<short>(ceil(cell_y));
			}
		}

		//Check if position is inside map
		if (0 <= x && 0 <= y && MAP_HEIGHT > y && MAP_WIDTH > x)
		{
            //Check for walls 
			if (0 == ipoint) 
			{
				if (Cell::Wall == imap[x][y])
				{
					output = 1;
				}
			}
            //Check for collectible
			else 
			{
				if (Cell::PowerUp == imap[x][y])
				{
					output = 1;
					imap[x][y] = Cell::Empty;
				}

				else if (Cell::Point == imap[x][y])
				{
					imap[x][y] = Cell::Empty;
					std::cout << "nom ";
					
				}
			}
		}
	}
    return output;
}