#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/Pacman.hpp"
#include "Headers/MapChecker.hpp"

Pacman::Pacman() :
    direction(0),
    position({0, 0})
{

}


void Pacman::update(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &imap)
{
    std::array<bool, 4> walls{};
	walls[0] = map_check(0, position.x, position.y - PAC_SPEED, imap);
	walls[1] = map_check(0, position.x - PAC_SPEED, position.y, imap);
	walls[2] = map_check(0, position.x, PAC_SPEED + position.y, imap);
    walls[3] = map_check(0, PAC_SPEED + position.x, position.y, imap);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (0 == walls[0])
		{
			direction = 0;
		}
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (0 == walls[1])
		{
			direction = 1;
		}
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (0 == walls[2])
		{
			direction = 2;
		}
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (0 == walls[3])
		{
			direction = 3;
		}
    }

    if (0 == walls[direction])
	{
        switch (direction)
        {
            case 0:
            {
                position.y -= PAC_SPEED;

                break;
            }

            case 1:
            {
                position.x -= PAC_SPEED;

                break;
            }

            case 2:
            {
                position.y += PAC_SPEED;

                break;
            }

            case 3:
            {
                position.x += PAC_SPEED;

                break;
            }
        }

    }

    if (-CELL_SIZE >= position.x)
	{
		position.x = CELL_SIZE * MAP_WIDTH - PAC_SPEED;
	}
	else if (CELL_SIZE * MAP_WIDTH <= position.x)
	{
		position.x = PAC_SPEED - CELL_SIZE;
	}
}

void Pacman::draw(sf::RenderWindow &iwindow)
{
    sf::CircleShape pac(CELL_SIZE / 2);
    pac.setFillColor(sf::Color(255, 255, 0));
    pac.setPosition(position.x, position.y);

    iwindow.draw(pac);
}

void Pacman::set_position(short ix, short iy)
{
    position = {ix, iy};
}