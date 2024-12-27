#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Core/GameWindowManager.h"
#include "Header/Event/EventManager.h"
#include "Header/Core/GameLoop.h"

using namespace Core;
using namespace Eventmanager;

int main()
{
	GameLoop* game_loop = new GameLoop();

	game_loop->initialize();
	while (game_loop->isGameRunning())
	{
		game_loop->pollEvent();
		game_loop->update();
		game_loop->render();
	}
}