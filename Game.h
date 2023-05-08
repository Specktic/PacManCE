#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        bool end;
        sf::Event ev;

        void initVar();
        void initWindow();

    public:
        //Constructor
        Game();

        //Destructor
        ~Game();

        //Getters

        //Setters

        //Methods
        const bool running() const;
        void eventCheck();

        void update();
        void render();


};
