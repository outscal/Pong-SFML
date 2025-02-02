#include "D:\unity\repos\SFML-Pong\Header\GameLoop.h"

namespace Core {
	void GameLoop::Initialize()
	{
		game_Window_Manager = new GameWindowManager();
		
		event_Manager = new EventManager();
		game_Window_Manager->Initialize();
	}

	void GameLoop::Update()
	{

	}

	bool GameLoop::IsGameRunning()
	{
		return game_Window_Manager->IsGameRunning();
	}

	void GameLoop::Render()
	{
		game_Window_Manager->ClearGameWindow();
		game_Window_Manager->DisplayGameWindow();
	}

	void GameLoop::PollEvent()
	{
		event_Manager->PollEvents(game_Window_Manager->GetGameWindow());
	}

}