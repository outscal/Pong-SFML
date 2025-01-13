#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

namespace EventM {
	class EventManager {
	public:
		void pollEvent(RenderWindow* game_window);
		bool isKeyPressed(Keyboard::Key key);
		bool isLeftMouseButtonClicked();
	};
}