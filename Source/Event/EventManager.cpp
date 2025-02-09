#include "../../Header/Event/EventManager.h"
#include <iostream>
namespace Event {
	void EventManager::pollEvents(RenderWindow* game_window)
	{
		sf::Event event;
		while (game_window->pollEvent(event))
		{
			if (isKeyPressed(sf::Keyboard::Escape)) 
			{
                game_window->close();
			}

			if (isLeftMouseButtonClicked())
			{
				sf::Vector2i mouseposition = sf::Mouse::getPosition(*game_window);

				std::cout << "Left click at " << mouseposition.x<<","<<mouseposition.y << std::endl;
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;
		return false;
	}
}