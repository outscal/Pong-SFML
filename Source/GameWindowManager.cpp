#include"../../Header/GameWindowManager.h"

namespace GameManager {
	void GameWindowsManager::GameWindowsManager::Initialize()
	{
		gameWindow = new RenderWindow();
		createGamewindows();
	}
	
	//void GameWindowsManager::render()
	//{
	//	

	//	
	//}
	RenderWindow* GameWindowsManager::getgamewindow()
	{
		return gameWindow;
	}

	bool GameWindowsManager::isGameRuning()
	{
		return gameWindow->isOpen();
	}

	void GameWindowsManager::createGamewindows()
	{
		gameWindow->create(VideoMode::getDesktopMode(),gameTile,Style::Default);
	}

	void GameWindowsManager::clearGameWindow()
	{
		gameWindow->clear(Color(0, 0, 0, 255));
	}

	void GameWindowsManager::displayGameWindow()
	{
		gameWindow->display();
	}



}
