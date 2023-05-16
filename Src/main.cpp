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
    // Map
    std::array<std::string, MAP_HEIGHT > map_schematic_1 = {
        " ################### ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #P                # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" #                 # ",
		" ################### "
    };

    //Map instance before reading schematic
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

	//Some lag thing-------------------------------------------------------------------------------
	unsigned lag = 0;
	std::chrono::time_point<std::chrono::steady_clock> prevTime;
	//---------------------------------------------------------------------------------------------

    //SFML events
    sf::Event event;

    //SFML window 
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "PMCE", sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

    //Instances
	Pacman pacman;

    //Reading map schematic
    map = read_map(map_schematic_1, pacman);

	//Some lag thing again--------------------------------------------------------------------------
	prevTime = std::chrono::steady_clock::now();

    //Game loop
    while (window.isOpen())
    {
		//More lag thing---------------------------------------------------------------------------
		unsigned deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - prevTime).count();
		lag += deltaTime;
		prevTime += std::chrono::microseconds(deltaTime);
		//-----------------------------------------------------------------------------------------

		while (FRAME_DURATION <= lag)
		{
			lag -= FRAME_DURATION;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed:
					{
						window.close();
					}
				}
			}

			if (FRAME_DURATION > lag)
			{
				//Update pacman
				pacman.update();
				
				//Clear
				window.clear();

				//Draw map state
				render_map(map, window);
				
				//Draw pacman
				pacman.draw(window);

				//Display game window 
				window.display();

			}
		}
    }
}