#include "../../Header/Event/EventManager.h"
#include <iostream>

using namespace Eventmanager;
using namespace sf;

void EventManager::pollEvents(RenderWindow* game_window)
{
    Event event;
    while (game_window->pollEvent(event)) 
    {
        switch (event.type)
        {
        case Event::Closed:
            game_window->close();
            break;
        case Event::KeyPressed:
            switch (event.key.code)
            {
            case Keyboard::Escape:
                game_window->close();
                break;
            }
            break;
        case Event::MouseButtonPressed:
            switch (event.mouseButton.button)
            {
            case Mouse::Left:
                float m_x = event.mouseButton.x;
                float m_y = event.mouseButton.y;
                std::cout << "Mouse Click Position: " << m_x << "," << m_y << "\n";
            }
                
        }

    }
}

//bool EventManager::isKeyPressed(sf::Keyboard::Key key)
//{
//    return false;
//}
