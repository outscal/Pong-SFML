#include "../../Header/Event/EventManager.h"
#include <iostream>

namespace Events
{

	void EventManager::pollEvents(sf::RenderWindow* gameWindow)
	{
		sf::Event event;
		while (gameWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow->close();
			}
			if (isKeyPressed(sf::Keyboard::Escape))
			{
				gameWindow->close();
			}
			if (isLeftMouseButtonPressed())
			{
				sf::Vector2i position = sf::Mouse::getPosition(*gameWindow);
				std::cout << "Left mouse click at: " << position.x << ", " << position.y << std::endl;
			}
		}
	}

	bool EventManager::isKeyPressed(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}

	bool EventManager::isLeftMouseButtonPressed()
	{
		return (sf::Mouse::isButtonPressed(sf::Mouse::Left));
	}

}