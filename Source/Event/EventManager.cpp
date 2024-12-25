#include "../../Header/Event/EventManager.h"
#include <iostream>

using namespace Eventmanager;
using namespace sf;

void EventManager::pollEvents(RenderWindow* game_window)
{
    Event event;
    while (game_window->pollEvent(event)) 
    {
        if (event.type == Event::Closed)
            game_window->close();
        if (isKeyPressed(Keyboard::Escape))
            game_window->close(); 
    }
}

bool EventManager::isKeyPressed(sf::Keyboard::Key key)
{
    return Keyboard::isKeyPressed(key);
}
