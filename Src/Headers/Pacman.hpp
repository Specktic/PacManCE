#pragma once

class Pacman
{
    unsigned char direction;

    Position position;

public:
    Pacman();

    void update(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &imap);
    void draw(sf::RenderWindow &window);
    void set_position(short ix ,short iy);
};