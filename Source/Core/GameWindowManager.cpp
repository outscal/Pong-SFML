#include "../../Header/Core/GameWindowManager.h";

namespace Core
{
	void GameWindowManager::initialize()
	{
		game_window = new RenderWindow();
		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		game_window->create(
			VideoMode(gameWindowWidth, gameWindowHeight),
			gameTitle);
	}

	bool GameWindowManager::isGameRunning()
	{
		return game_window->isOpen();
	}

	void GameWindowManager::render()
	{

	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}
}