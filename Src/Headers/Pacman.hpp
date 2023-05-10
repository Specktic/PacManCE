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

    //Gets direction 
    unsigned char get_direction();

    //Draws pacman 
    void draw();

    //Resets
    void reset();
    
    //Sets death value
    void set_death();

    //Sets pacman's position
    void set_position();

    //Updates pacman
    void update();

    //Gets position
    Position get_position();
};