#pragma once

#include "Globals.hpp"

class Pacman
{
    //Dead? Skill issue tbh 
    bool death;

    //Direction facing 
    unsigned char direction;

    //The yellow critter's postion 
    Position position;

public:
    Pacman();

    //Gets death value
    bool get_death();

    //Sets death value
    void set_death(bool ideath);

    //Gets direction 
    unsigned char get_direction();

    //Sets direction 
    void set_direction(unsigned char dir);

    //Gets position
    Position get_position();

    //Sets pacman's position
    void set_position(short ix, short iy);

    //Updates pacman
    void update(std::array< std::array < Cell, MAP_HEIGHT >, MAP_WIDTH > &imap);

    //Resets
    void reset();

    //Draws pacman on play window
    void draw(sf::RenderWindow &iwindow);
};