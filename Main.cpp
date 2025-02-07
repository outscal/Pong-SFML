#include <iostream>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"

using namespace Core;
using namespace Event;

int main()
{
    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    */
    EventManager eventManager;
    GameWindowManager gameWindowManager;
    gameWindowManager.initialize();

    while (gameWindowManager.isGameRunning())
    {
        eventManager.pollEvents(gameWindowManager.getGameWindow());
        gameWindowManager.render();
    }
}