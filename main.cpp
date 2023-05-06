#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "nom nom nom");
    window.setFramerateLimit(30);

    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Update window


        //Draw on window


        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}