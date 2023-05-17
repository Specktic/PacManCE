#include "SFML/Graphics.hpp"

#include "Headers/Globals.hpp"
#include "Headers/Ghost.hpp"
#include "Headers/MapChecker.hpp"

Ghost::Ghost(unsigned char iid) :
    id(iid),
    position({0, 0})
{

}

void Ghost::draw(sf::RenderWindow &iwindow)
{
    sf::CircleShape gho(CELL_SIZE / 2);
    sf::RectangleShape st(sf::Vector2f(CELL_SIZE, CELL_SIZE / 2));

    gho.setFillColor(sf::Color(255, 0, 0));
    st.setFillColor(sf::Color(255, 0, 0));

    gho.setPosition(position.x, position.y);
    st.setPosition(position.x, position.y + gho.getRadius());

    iwindow.draw(gho);
    iwindow.draw(st);

}

void Ghost::set_Position(short ix, short iy)
{
    position = {ix, iy};
}

void Ghost::update(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &imap)
{
    std::array<bool, 4> walls{};
    walls[0] = map_check(0, position.x, position.y - GHOST_SPEED, imap);
	walls[1] = map_check(0, position.x - GHOST_SPEED, position.y, imap);
	walls[2] = map_check(0, position.x, GHOST_SPEED + position.y, imap);
    walls[3] = map_check(0, GHOST_SPEED + position.x, position.y, imap);
}

