#include "../../Header/Core/GameWindowManager.h"

namespace Core {
	void GameWindowManager::initialize()
	{
		// Allocate memory for the render window object
		game_window = new RenderWindow();
		// Set up the window with configured properties
		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		//game_window->create(VideoMode(game_window_width, game_window_height), game_title);
		game_window->create(sf::VideoMode::getDesktopMode(), game_title, sf::Style::Fullscreen);
	}

	bool GameWindowManager::isGameRunning()
	{
		return game_window->isOpen();
	}

	void GameWindowManager::clearGameWindow()
	{
		game_window->clear();
	}

	void GameWindowManager::displayGameWindow()
	{
		game_window->display();//return game_window->display(), as given in course. not sure why.
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}
}