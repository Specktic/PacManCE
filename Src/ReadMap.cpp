
#include <array>
#include <string>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/Pacman.hpp"
#include "Headers/ReadMap.hpp"

//Reads map drawings and converts each string into an according cell
std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> read_map(const std::array<std::string, MAP_HEIGHT > &dmap, Pacman &ipac)
{
    //Output map that is to be displayed on screen 
    std::array< std::array < Cell, MAP_HEIGHT >, MAP_WIDTH > output;

    for (unsigned char i = 0; i < MAP_HEIGHT; i++)
    {
        for (unsigned char j = 0; j < MAP_WIDTH; j++)
        {

            output[i][j] = Cell::Empty;


            switch (dmap[i][j])
            {
                case ' ':
                {
                    output[i][j] = Cell::Empty;

                    break;
                }

                case '#':
                {
                    output[i][j] = Cell::Wall;

                    break;
                }

                case '.':
                {
                    output[i][j] = Cell::Point;

                    break;
                }

                case 'o':
                {
                    output[i][j] = Cell::PowerUp;

                    break;
                }

                case 'P':
                {
                    ipac.set_position(CELL_SIZE * i, CELL_SIZE * j);

                    break;
                }

            }

        }

    }

    return output;

}