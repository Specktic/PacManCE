#include <array>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/DrawMap.hpp"

void render_map(const std::array< std::array< Cell, MAP_HEIGHT >, MAP_WIDTH > &i_map, sf::RenderWindow &window)
{
    sf::RectangleShape cell_shape(sf::Vector2f(CELL_SIZE, CELL_SIZE));

    for (unsigned char i = 0; i < MAP_WIDTH; ++i)
    {
        for (unsigned char j = 0; j < MAP_HEIGHT; ++j)
        {
            switch (i_map[i][j])
            {
                case Cell::Wall:
                {
                    cell_shape.setFillColor(sf::Color(0,0,255));

                    window.draw(cell_shape);
                }
            }
        }
    }
}

