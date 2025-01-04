#include"../../Header/EventManager.h"
#include<iostream>
using namespace sf;
namespace Event {
	void EventManager::PoolEvent(RenderWindow* gameWindow)
	{
		sf::Event event;

		while (gameWindow->pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				gameWindow->close();
				
				}
			if (IskeyPressed(sf::Keyboard::Escape)) {
				gameWindow->close();
			}
			if (IsLeftButtonPressed()) {

				sf::Vector2i position = sf::Mouse::getPosition(*gameWindow);

				
				std::cout << "Left mouse click at: " << position.x << ", " << position.y << std::endl;
			}
		}
	}
	bool EventManager::IskeyPressed(Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}
	bool EventManager::IsLeftButtonPressed()
	{
		return sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}
}