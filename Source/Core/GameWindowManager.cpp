#include "../../Header/Core/GameWindowManager.h"
namespace Core {
	void GameWindowManager::initialize() {
		game_window = new RenderWindow();
		createGameWindow();
	}
	void GameWindowManager::createGameWindow() {
		game_window->create(sf::VideoMode::getDesktopMode(), game_title, sf::Style::Default);
	}
	bool GameWindowManager::isGameRunning() {
		return game_window->isOpen();
	}
	void GameWindowManager::clearGameWindow()
	{
		game_window->clear();
	}
	void GameWindowManager::displayGameWindow()
	{
		return game_window->display();
	}
	RenderWindow* GameWindowManager::getGameWindow() {
		return game_window;
	}
}