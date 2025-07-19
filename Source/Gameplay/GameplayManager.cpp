#include "../../Header/Gameplay/GameplayManager.h"


namespace Gameplay
{
	GameplayManager::GameplayManager(Events::EventManager* manager) 
		
	{
		initialize();
		event_manager = manager;
		time_service = Utility::TimeService::getInstance();
	}

	void GameplayManager::initialize()
	{
		player1_paddle = new Paddle(player1_position_x, player1_position_y);
		player2_paddle = new Paddle(player2_position_x, player2_position_y);
		ball = new Ball(player1_paddle->getPaddleSprite(), player2_paddle->getPaddleSprite());
		boundary = new Boundary();
		ui_service = new Core::UIService();
	}

	void GameplayManager::render(sf::RenderWindow* game_window)
	{
		player1_paddle->render(game_window);
		player2_paddle->render(game_window);
		ball->render(game_window);
		boundary->render(game_window);
		ui_service->render(game_window);
	}

	void GameplayManager::update()
	{
		time_service->update();
		ball->update();
		player1_paddle->update(event_manager->isKeyPressed(Keyboard::W),
			event_manager->isKeyPressed(Keyboard::S));
		player2_paddle->update(event_manager->isKeyPressed(Keyboard::Up),
			event_manager->isKeyPressed(Keyboard::Down));
		ui_service->update();
	}

	void GameplayManager::UpdateScore() {
		// Left side out - Player 2 scores!
		if (ball->isLeftCollisionOccured()) {
			ui_service->incrementPlayer2Score();
			ball->updateLeftCollisionState(false);
			resetPlayers();  // You'll implement it next
		}

		// Right side out - Player 1 scores!
		if (ball->isRightCollisionOccured()) {
			ui_service->incrementPlayer1Score();
			ball->updateRightCollisionState(false);
			resetPlayers();  // You'll implement it next
		}
	}
	void GameplayManager::resetPlayers() {
		player1_paddle->reset(player1_position_x, player1_position_y);
		player2_paddle->reset(player2_position_x, player2_position_y);
	}

	
}