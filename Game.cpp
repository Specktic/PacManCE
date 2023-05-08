#include "Game.h"

void Game::initVar()
{
    this->end = false;
}

void Game::initWindow()
{
    this->videoMode = sf::VideoMode(800, 800);
    this->window = new sf::RenderWindow(this->videoMode, "", sf::Style::Close | sf::Style::Titlebar);
}

//Constructor
Game::Game()
{
    this->initVar();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

//Methods
const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::eventCheck()
{
    while(this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::update()
{
    this->eventCheck();
}

void Game::render()
{
    this->window->clear();

    //

    this->window->display();
}