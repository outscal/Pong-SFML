#include "D:\unity\repos\SFML-Pong\Header\Core\GameWindowManager.h"
namespace Core {
	void GameWindowManager::Initialize() {
		game_Window = new RenderWindow();
		CreateGameWindow();
	}

	void GameWindowManager::CreateGameWindow() {
		game_Window->create(sf::VideoMode::getDesktopMode(), game_Title, sf::Style::Default);
	}

	bool GameWindowManager::IsGameRunning() {
		return game_Window->isOpen();
	}


	void GameWindowManager::ClearGameWindow()
	{
		game_Window->clear(sf::Color(140, 130, 100, 200));
	}

	void GameWindowManager::DisplayGameWindow()
	{
		game_Window->display();
	}

	RenderWindow* GameWindowManager::GetGameWindow() {
		return game_Window;
	}
}