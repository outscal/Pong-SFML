#include <iostream>
#include <SFML/Graphics.hpp>
#include "D:\unity\repos\SFML-Pong\Header\Core\GameWindowManager.h"
#include "D:\unity\repos\SFML-Pong\Header\Event\EventManager.h"
#include "D:\unity\repos\SFML-Pong\Header\Core\GameLoop.h"

//using namespace Core;

int main()
{
   /* sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
    }*/

   /* Core::GameWindowManager gameWindowManager;
    MyEvent::EventManager eventManager;
    gameWindowManager.Initialize();
    while (gameWindowManager.IsGameRunning()) {
        eventManager.PollEvents(gameWindowManager.GetGameWindow());
    }*/
    Core::GameLoop* gameLoop= new GameLoop();
    gameLoop->Initialize();
    while (gameLoop->IsGameRunning()) {
        gameLoop->PollEvent();
        gameLoop->Update();
        gameLoop->Render();
    }
    return 0;
}