#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

namespace MyEvent {
	class EventManager {
		
	public:

		void PollEvents(RenderWindow* game_Window);

		bool IsKeyPressed(sf::Keyboard::Key key);

		bool ISMouseLeftButtonClicked();
	};
}
