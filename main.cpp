#include <iostream>
#include "Game.h"

int main()
{

    //Init game object
    Game game;

    //Game loop
    while(game.running())
    {
        game.update();
        game.render();
    }


    //Ending
    return 0;
}