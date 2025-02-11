#include <iostream>
#include "../../Header/Core/GameLoop.h"

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

    /*
    EventManager eventManager;
    GameWindowManager gameWindowManager;
    gameWindowManager.initialize();

    while (gameWindowManager.isGameRunning())
    {
        eventManager.pollEvents(gameWindowManager.getGameWindow());
        gameWindowManager.render();
    }
    */

    GameLoop* game_loop_manager = new GameLoop();
    game_loop_manager->initialize();

    while (game_loop_manager->isGameRunning())
    {
        game_loop_manager->pollEvent();
        game_loop_manager->update();
        game_loop_manager->render();
    }
}