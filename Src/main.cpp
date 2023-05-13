#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/ReadMap.hpp"
#include "Headers/DrawMap.hpp"
#include "Headers/Pacman.hpp"

int main()
{
    // Game won
    bool game_won = 0;

    // Map
    std::array<std::string, MAP_HEIGHT > map_schematic_1 = {
        " ################### ",
		" #        #        # ",
		" # ## ### # ### ## # ",
		" #                 # ",
		" # ## # ##### # ## # ",
		" #    #   #   #    # ",
		" #### ### # ### #### ",
		"    # #       # #    ",
		"##### # ## ## # #####",
		"#       #   #       #",
		"##### # ##### # #####",
		"    # #       # #    ",
		" #### # ##### # #### ",
		" #        #        # ",
		" # ## ### # ### ## # ",
		" #  #           #  # ",
		" ## # # ##### # # ## ",
		" #    #   #   #    # ",
		" # ###### # ###### # ",
		" #                 # ",
		" ################### "
    };

    //Map instance before reading schematic
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> play_map;

    //SFML events
    sf::Event event;

    //SFML window 
    sf::RenderWindow play_window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "PMCE", sf::Style::Close);
    play_window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    //Object instances

    //Reading map schematic
    play_map = read_map(map_schematic_1);

    //Game loop 
    while (play_window.isOpen())
    {
        if (event.type == sf::Event::Closed)
        {
            play_window.close();
        }
		

        play_window.clear();

        render_map(play_map, play_window);

        play_window.display();

    }

}