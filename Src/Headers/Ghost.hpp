#pragma once

class Ghost
{ 
    unsigned char id;

    unsigned char direction;

    Position position;

public:
    Ghost(unsigned char iid);

    void draw(sf::RenderWindow &iwindow);
    void set_Position(short ix, short iy);
    void update(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &imap);
};