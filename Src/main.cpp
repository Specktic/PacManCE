#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "Headers/Globals.hpp"
#include "Headers/ReadMap.hpp"
#include "Headers/RenderMap.hpp"
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
		" #        P        # ",
		" # ## # ##### # ## # ",
		" #    #   #   #    # ",
		" #### ### # ### #### ",
		"    # #       # #    ",
		"##### # ##### # #####",
		"#       #####       #",
		"##### # ##### # #####",
		"    # #       # #    ",
		" #### # ##### # #### ",
		" #        #        # ",
		" # ## ### # ### ## # ",
		" #  #           #  # ",
		" ## # # ##### # # ## ",
		" #    #   #   #    # ",
		" # ###### # ###### # ",
		" #        P        # ",
		" ################### "
    };

    //Map instance before reading schematic
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> play_map{};

    //SFML events
    sf::Event event;

    //SFML window 
    sf::RenderWindow play_window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "PMCE", sf::Style::Close);
    play_window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    //Instances
	Pacman pac;

	//Pacman sprite
	sf::CircleShape yellowBall (static_cast<float>(CELL_SIZE));
	yellowBall.setFillColor(sf::Color::Yellow);

    //Reading map schematic
    play_map = read_map(map_schematic_1, pac);

    //Game loop 
    while (play_window.isOpen())
    {
        while (play_window.pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed:
					{
						play_window.close();
					}
				}
			}
		//Clear
        play_window.clear();
		//Window

		pac.update(play_map);
		pac.draw(play_window);

        render_map(play_map, play_window);

		//Display
        play_window.display();
		//Window
    }
}