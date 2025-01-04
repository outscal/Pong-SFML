#include <iostream>
#include <SFML/Graphics.hpp>


#include "D:\Unity Projects 2024\Co-Op Snake 2D\Pong-SFML\Assets\Header\Core\GameLoop.h"
using namespace sf;
using namespace Core;
int main()
{

    GameLoop* game_loop_Manager = new GameLoop();
    game_loop_Manager->initialize();

    while (game_loop_Manager->isGameRunning())
    {
        game_loop_Manager->pollEvent();
        game_loop_Manager->Update();
        game_loop_Manager->Render();
    }
    
    return 0;
    
}