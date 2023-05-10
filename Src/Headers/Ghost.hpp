#pragma once

#include "Globals.hpp"

class Ghost
{
    //Movement type
    bool movement_type;

    //Current direction
    unsigned char direction;

    //Identifier 
    // 0 = Blinky   (RED)
    // 1 = Pinky    (PINK)
    // 2 = Inky     (CYAN)
    // 3 = Clyde    (ORANGE)
    unsigned char id;

    //Movement target
    Position target;

public:
    Ghost();

    //Collision with player
    bool pacman_collision;

    //Distance from target
    float get_target_distance();

    //Draws the ghost
    void draw();

    //Resets
	void reset();

    //Sets the ghost's position
	void set_position();

    //Changes movement type
	void switch_mode();

    //Updates the ghost
	void update();

    //Updates the ghost's current target 
	void update_target();

	Position get_position();
};