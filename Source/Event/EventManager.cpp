#include "../../Header/Event/EventManager.h"

using namespace Event;

void EventManager::pollEvents(RenderWindow* game_window)
{
    sf::Event event;
    while (game_window->pollEvent(event)) {

        // Check for Escape key
        if (isKeyPressed(sf::Keyboard::Escape)) {
            game_window->close();
        }
    }
}

bool EventManager::isKeyPressed(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}
