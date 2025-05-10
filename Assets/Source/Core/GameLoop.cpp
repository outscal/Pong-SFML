#include "../../Header/Core/GameLoop.h"
namespace Core
{
	void Core::GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager();
		event_manager = new EventManager();
		gameplay_manager = new GameplayManager(event_manager);
		game_window_manager->initialize();
		soundmanager = new SoundManager();
		SoundManager::PlayBackgroundMusic();
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
		gameplay_manager->update();
	}

	void Core::GameLoop::Render()
	{
		game_window_manager->clearGameWindow();
		gameplay_manager->render(game_window_manager->getGameWindow());
		game_window_manager->displayGameWindow();
	}

}