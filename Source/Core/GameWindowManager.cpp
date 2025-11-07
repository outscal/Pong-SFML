#include "../../Header/Core/GameWindowManager.h"

using namespace Core;
using namespace sf;

void GameWindowManager::initialize()
{
    game_window.create(sf::VideoMode(game_window_width, game_window_height), game_title);
    game_window.setFramerateLimit(60);
}
GameWindowManager::GameWindowManager() 
{
    
}
bool GameWindowManager::isGameRunning()
{
    return game_window.isOpen();
}

sf::RenderWindow* GameWindowManager::getGameWindow()
{
    return &game_window;
}

void GameWindowManager::clearGameWindow()
{
    game_window.clear(sf::Color::Black);
}

void GameWindowManager::displayGameWindow()
{
    game_window.display();
}

