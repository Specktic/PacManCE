#pragma once

class Pacman
{
    unsigned char direction;

    Position position;

public:
    Pacman();
    
    void update();
    void draw(sf::RenderWindow &window);
    void set_position(short ix ,short iy);
};