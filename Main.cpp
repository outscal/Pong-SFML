#include "Header/Core/GameWindowManager.h"
#include "Header/Event/EventManager.h"


int main()
{
	Core::GameWindowManager gameWindowManager;
	EventM::EventManager eventManager;

	gameWindowManager.initialize();

	while (gameWindowManager.isGameRunning()) {
		eventManager.pollEvent(gameWindowManager.getGameWindow());
		gameWindowManager.render();
	}

	return 0;
}