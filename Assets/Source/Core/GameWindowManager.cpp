#include "../../Header/Core/GameWindowManager.h"


namespace Core
{
	void Core::GameWindowManager::initialize()
	{
		game_window = new RenderWindow();
		createGameWindow();
	}



	void Core::GameWindowManager::createGameWindow()
	{

		game_window->create(sf::VideoMode::getDesktopMode(),
			game_title, sf::Style::Fullscreen);

	}

	bool Core::GameWindowManager::isGameRunning()
	{
		return game_window->isOpen();
	}

	
	void GameWindowManager::clearGameWindow()
	{
		game_window->clear();
	}
	void GameWindowManager::displayGameWindow()
	{
		game_window->display();
	}
	RenderWindow* Core::GameWindowManager::getGameWindow()
	{
		return game_window;
	}

}