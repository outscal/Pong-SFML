#include "../../Header/Core/GameWindowManager.h"


namespace Core
{
	void GameWindowManager::createGameWindow()
	{
		// Create the window with specified dimensions and title
		game_window->create(VideoMode(game_window_width, game_window_height),game_title);
	}
	void GameWindowManager::initialize()
	{
		// Allocate memory for the render window object
		game_window = new RenderWindow();
		// Set up the window with configured properties
		createGameWindow();
	}

	RenderWindow* Core::GameWindowManager::getGameWindow()
	{
		return game_window;
	}
	bool GameWindowManager::isGameRunning()
	{
		// Return true if window is open, false if closed
		return game_window->isOpen();
	}
}
