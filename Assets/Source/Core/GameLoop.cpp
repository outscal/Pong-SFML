#include "../../Header/Core/GameLoop.h"
namespace Core
{
	void Core::GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager();
		event_manager = new EventManager();
		game_window_manager->initialize();
	}

	bool Core::GameLoop::isGameRunning()
	{
		return game_window_manager->isGameRunning();
	}

	void Core::GameLoop::pollEvent()
	{
		event_manager->pollEvents(game_window_manager->getGameWindow());
	}

	void Core::GameLoop::Update()
	{
	}

	void Core::GameLoop::Render()
	{
		game_window_manager->clearGameWindow();
		game_window_manager->displayGameWindow();
	}

}