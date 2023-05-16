#include <array>
#include <cmath>

#include "Headers/Globals.hpp"
#include "Headers/Collisions.hpp"

bool collision(short x, short y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map)
{
    bool out = 0;

    //Get pacman's esxact position
    float x_cell = x / static_cast<float>(CELL_SIZE);
    float y_cell = y / static_cast<float>(CELL_SIZE);

    //Max 4 intersecting cells
    for (unsigned char i; i < 4; i++)
    {
        short x2 = 0;
		short y2 = 0;

        switch (i)
        {
            //Top left
            case 0:
            {
                x2 = static_cast<short>(floor(x_cell));
                y2 = static_cast<short>(floor(y_cell));

                break;
            }

            //Top left
            case 1:
            {
                x2 = static_cast<short>(floor(x_cell));
                y2 = static_cast<short>(floor(y_cell));

                break;
            }

            //Top left
            case 2:
            {
                x2 = static_cast<short>(floor(x_cell));
                y2 = static_cast<short>(floor(y_cell));

                break;
            }

            //Top left
            case 3:
            {
                x2 = static_cast<short>(floor(x_cell));
                y2 = static_cast<short>(floor(y_cell));

                break;
            }

        }

    }

    return out;

}

