#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Core/GameWindowManager.h"
#include "Header/Event/EventManager.h"

int main()
{
	Core::GameWindowManager gameWindowManager;
	Events::EventManager eventManager;
	gameWindowManager.initialize();
	
	while (gameWindowManager.isGameRunning())
	{
		eventManager.pollEvents(gameWindowManager.getGameWindow());
		gameWindowManager.render();
	}

	return 0;
}