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