#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/Pacman.hpp"

Pacman::Pacman() :
    direction(0),
    position({0, 0})
{

}


void Pacman::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        direction = 3;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        direction = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        direction = 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        direction = 0;
    }

    switch (direction)
    {
        case 0:
        {
            position.x += PAC_SPEED;

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
            position.y -= PAC_SPEED;

            break;
        }
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