
#include <array>
#include <string>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/Pacman.hpp"
#include "Headers/ReadMap.hpp"
#include "Headers/Ghost.hpp"

//Reads map drawings and converts each string into an according cell
std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> read_map(const std::array<std::string, MAP_HEIGHT > &dmap, Pacman &ipac, Ghost &ighost)
{
    //Output map that is to be displayed on screen 
    std::array< std::array < Cell, MAP_HEIGHT >, MAP_WIDTH > output;

    for (unsigned char i = 0; i < MAP_HEIGHT; i++)
    {
        for (unsigned char j = 0; j < MAP_WIDTH; j++)
        {

            output[j][i] = Cell::Empty;


            switch (dmap[i][j])
            {
                case ' ':
                {
                    output[j][i] = Cell::Empty;

                    break;
                }

                case '#':
                {
                    output[j][i] = Cell::Wall;

                    break;
                }

                case '.':
                {
                    output[j][i] = Cell::Point;

                    break;
                }

                case 'o':
                {
                    output[j][i] = Cell::PowerUp;

                    break;
                }

                case 'P':
                {
                    ipac.set_position(CELL_SIZE * j, CELL_SIZE * i);

                    break;
                }

                case 'G':
                {
                    ighost.set_Position(CELL_SIZE * j, CELL_SIZE * i);

                    break;
                }

            }

        }

    }

    return output;

}