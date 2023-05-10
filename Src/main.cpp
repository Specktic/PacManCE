#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"

int main()
{
    // Game won
    bool game_won = 0;

    // Framerate independance
    unsigned lag = 0;
    std::chrono::time_point<std::chrono::steady_clock> previous_time;

    // Maps

    //SFML events
    sf::Event event;

    //SFML window 
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "PMCE", sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    //Object instances

    //Game loop 
    while (window.isOpen())
    {
        window.clear();
        window.display();

    }
}