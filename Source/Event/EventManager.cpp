#include "../../Header/Event/EventManager.h"
#include <iostream>
using namespace std;

namespace Event
{
    void EventManager::pollEvents(RenderWindow* game_window)
    {
        sf::Event event;
        while (game_window->pollEvent(event))
        {
            // Previous Code

            // Check for Escape key
            if (isKeyPressed(sf::Keyboard::Escape))
            {
                game_window->close();
            }

            if (isLeftMouseButtonClicked())
            {
                sf::Vector2i position = sf::Mouse::getPosition(*game_window);

                // Log the mouse position
                cout << "Left mouse click at: " << position.x << ", " << position.y << endl;
            }
        }
    }

    bool EventManager::isKeyPressed(sf::Keyboard::Key key)
    {
        // Detect if a specific key is pressed
        return sf::Keyboard::isKeyPressed(key);
    }

    bool EventManager::isLeftMouseButtonClicked()
    {
        // Detect if the left mouse button is clicked
        return (sf::Mouse::isButtonPressed(sf::Mouse::Left));
    }

    
}

    

