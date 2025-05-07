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
    game_loop_manager->initialize();
    
    

    while (game_loop_manager->isGameRunning()) {

        game_loop_manager->pollEvent();
        game_loop_manager->update();
        game_loop_manager->render();
    }
    return 0;
}


