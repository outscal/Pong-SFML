#include <iostream>
#include <SFML/Graphics.hpp>

#include "Header/Core/GameWindowManager.h"

using namespace Core;

int main()
{
	GameWindowManager game_window_manager;

	game_window_manager.initialize();

	while (game_window_manager.isGameRunning())
	{
		game_window_manager.render();
	}
}