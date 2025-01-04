#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
namespace Event {

	class EventManager {

	public:
		void PoolEvent(RenderWindow* gameWindow);
		bool IskeyPressed(Keyboard::Key key);
		bool IsLeftButtonPressed();

	};
}