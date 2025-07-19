#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Core/GameLoop.h"

int main()
{
	
	Core::GameLoop* gameLoop = new Core::GameLoop();
	gameLoop->initialize();
	
	while (gameLoop->isGameRunning())
	{
		gameLoop->pollEvents();
		gameLoop->update();
		gameLoop->render();
	}

	return 0;
}