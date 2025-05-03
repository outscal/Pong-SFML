#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Core/GameLoop.h"

using namespace sf;
using namespace Core;

int main()
{
    CoustomEvent::EventManager eventManager;
    Core::GameWindowManager gameWindowManager;
    GameLoop* game_loop_manager = new GameLoop();


    gameWindowManager.initialize();
    //gameWindowManager.initialize();
    game_loop_manager->initialize();
    
    

    while (game_loop_manager->isGameRunning()) {

        game_loop_manager->pollEvent();
        game_loop_manager->update();
        game_loop_manager->render();
    }
    return 0;
}


//sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//sf::CircleShape shape(100.f);
//shape.setFillColor(sf::Color::Green);
//
//while (window.isOpen())
//{
//    sf::Event event;
//    while (window.pollEvent(event))
//    {
//        if (event.type == sf::Event::Closed)
//            window.close();
//    }
//
//    window.clear();
//    window.draw(shape);
//    window.display();