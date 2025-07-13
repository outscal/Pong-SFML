#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Events
{
	class EventManager
	{
	public:
		void pollEvents(RenderWindow* gameWindow);
		bool isKeyPressed(Keyboard::Key key);
		bool isLeftMouseButtonPressed();

	};
}