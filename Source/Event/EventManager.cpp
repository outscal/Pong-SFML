#include "../../Header/Event/EventManager.h"

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
		}
	}

	bool EventManager::isKeyPressed(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}

}