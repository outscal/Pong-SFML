#include "D:\unity\repos\SFML-Pong\Header\Core\GameLoop.h"
#include "D:\unity\repos\SFML-Pong\Header\Core\GameWindowManager.h"

namespace Core {
	void GameLoop::Initialize()
	{
		game_Window_Manager = new GameWindowManager();
		
		event_Manager = new EventManager();
		game_Window_Manager->Initialize();
		gameplayManager = new GamePlayManager(event_Manager);
		

	}

	void GameLoop::Update()
	{
		gameplayManager->Update();
	}

	bool GameLoop::IsGameRunning()
	{
		return game_Window_Manager->IsGameRunning();
	}

	void GameLoop::Render()
	{
		game_Window_Manager->ClearGameWindow();
		gameplayManager->Render(game_Window_Manager->GetGameWindow());
		game_Window_Manager->DisplayGameWindow();
		
	}

	void GameLoop::PollEvent()
	{
		event_Manager->PollEvents(game_Window_Manager->GetGameWindow());
	}

}