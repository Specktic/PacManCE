#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/Pacman.hpp"
#include "Headers/Collisions.hpp"

Pacman::Pacman() :
    death(0),
    direction(0),
    position({0,0})
{
}

bool Pacman::get_death()
{
    return death;
}

void Pacman::set_death(bool ideath)
{
    death = ideath;
}

unsigned char Pacman::get_direction()
{
    return direction;
}

void Pacman::set_direction(unsigned char dir)
{
    direction = dir;
}

Position Pacman::get_position()
{
    return position;
}

void Pacman::set_position(short ix, short iy)
{
	position = {ix, iy};
}

void Pacman::update(std::array< std::array < Cell, MAP_HEIGHT >, MAP_WIDTH > &imap)
{
    std::array< bool, 4 > walls{};
    walls[0] = collision(PAC_SPEED + position.x, position.y, imap);
    walls[1] = collision(position.x, position.y - PAC_SPEED, imap);
    walls[2] = collision(position.x - PAC_SPEED, position.y, imap);
    walls[3] = collision(position.x, PAC_SPEED + position.y, imap);

    //Can't turn into a wall
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    { 
        if (!walls[0])
        {
            direction = 0;
        }
    }

    //Can't turn into a wall
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (!walls[1])
        {
            direction = 0;
        }
    }

    //Can't turn into a wall
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (!walls[2])
        {
            direction = 0;
        }
    }

    //Can't turn into a wall
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (!walls[3])
        {
            direction = 0;
        }
    }

    //No wall => move
    if (!walls[direction])
    {
        switch(direction)
        {
            case 0:
            {
                position.x += PAC_SPEED;
                break;
            }

            case 1:
            {
                position.x += PAC_SPEED;
                break;
            }

            case 2:
            {
                position.x += PAC_SPEED;
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

void Pacman::reset()
{
    death = 0;
    direction = 0;
}

void Pacman::draw(sf::RenderWindow &window)
{
    sf::CircleShape circle(CELL_SIZE / 2);
    circle.setFillColor(sf::Color(255, 255, 0));
    circle.setPosition(position.x, position.y);
    window.draw(circle);
}