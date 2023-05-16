#include <array>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/RenderMap.hpp"

void render_map(const std::array< std::array <Cell,MAP_HEIGHT >, MAP_WIDTH > &imap, sf::RenderWindow &window)
{
    sf::RectangleShape cell_shape(sf::Vector2f(CELL_SIZE,CELL_SIZE));

    for (unsigned char i = 0; i < MAP_WIDTH; i++)
    {
        for(unsigned char j = 0; j < MAP_HEIGHT; j++)
        {
            switch (imap[i][j])
            {
                case Cell::Wall:
                {
                    cell_shape.setPosition(CELL_SIZE * i, CELL_SIZE * j);
                    cell_shape.setFillColor(sf::Color(40, 40, 255));
                    window.draw(cell_shape);
                }
            }
        }
    }
}