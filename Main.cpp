#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Core/GameWindowManager.h"
#include "Header/Event/EventManager.h"
#include "Header/GameLoop/GameLoop.h"

using namespace Event;

int main()
{
    // Step 1: Create the GameLoop object
    GameLoop* game_loop_manager = new GameLoop();

    // Step 2: Initialize the game environment
    game_loop_manager->initialize();

    // Step 3: Run the game loop
    while (game_loop_manager->isGameRunning())
    {
        game_loop_manager->pollEvent();
        game_loop_manager->update();
        game_loop_manager->render();
    }

    return 0;
}