#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager(Events::EventManager* manager)
	{
		initialize();
		event_manager = manager;
	}

	void GameplayManager::initialize()
	{
		player1_paddle = new Paddle(player1_position_x, player1_position_y);
		player2_paddle = new Paddle(player2_position_x, player2_position_y);
		ball = new Ball();
	}

	void GameplayManager::render(sf::RenderWindow* game_window)
	{
		player1_paddle->render(game_window);
		player2_paddle->render(game_window);
		ball->render(game_window);
	}

	void GameplayManager::update()
	{
		ball->update();
		player1_paddle->update(event_manager->isKeyPressed(Keyboard::W),
			event_manager->isKeyPressed(Keyboard::S));
		player2_paddle->update(event_manager->isKeyPressed(Keyboard::Up),
			event_manager->isKeyPressed(Keyboard::Down));
	}
}