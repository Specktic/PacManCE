#include <array>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/RenderMap.hpp"

void render_map(const std::array< std::array <Cell,MAP_HEIGHT >, MAP_WIDTH > &imap, sf::RenderWindow &window)
{
    sf::RectangleShape cell_shape(sf::Vector2f(CELL_SIZE,CELL_SIZE));

    sf::CircleShape point_shape;
    point_shape.setFillColor(sf::Color(255, 255, 255));

    for (unsigned char i = 0; i < MAP_WIDTH; i++)
    {
        for(unsigned char j = 0; j < MAP_HEIGHT; j++)
        {
            switch (imap[i][j])
            {
                
                case Cell::Point:
                {
                    point_shape.setRadius(CELL_SIZE / 8 );
                    point_shape.setPosition(CELL_SIZE * i + (CELL_SIZE / 2 - point_shape.getRadius()), CELL_SIZE * j + (CELL_SIZE / 2 - point_shape.getRadius()));
                    window.draw(point_shape);

                    break;
                }

                case Cell::Wall:
                {
                    cell_shape.setPosition(CELL_SIZE * i, CELL_SIZE * j);
                    cell_shape.setFillColor(sf::Color(40, 40, 255));
                    window.draw(cell_shape);

                    break;
                }
            }
        }
    }
}