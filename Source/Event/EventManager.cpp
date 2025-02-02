#include "D:\unity\repos\SFML-Pong\Header\Event\EventManager.h"
#include <iostream>
using namespace std;
namespace MyEvent {

	void EventManager::PollEvents(RenderWindow* game_Window)
	{
		sf::Event event;
		while (game_Window->pollEvent(event)) {

			if (IsKeyPressed(sf::Keyboard::Escape)) {
				game_Window->close();
				cout << "ESC clicked"<<endl;
			}
			if (event.type == sf::Event::Closed) {
				game_Window->close();
				cout << "x clicked"<<endl;
			}
			if (ISMouseLeftButtonClicked())
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition();
				cout << "mouse postion is  X = " << mousePosition.x<<"  Y = "<<mousePosition.y<<endl;
;			}
		}
	}

	bool EventManager::IsKeyPressed(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}
	bool EventManager::ISMouseLeftButtonClicked()
	{
		return sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}
}
