#include "../../Header/Gameplay/GameplayManager.h"

using namespace Gameplay;

void GameplayManager::initialize() {
	ball = new Ball();
	player1 = new Paddle(player1_position_x, player1_position_y);
	player2 = new Paddle(player2_postion_x, player2_postion_y);
	boundary = new Boundary();
}

void GameplayManager::update()
{
	time_service->update();
	ball->update(player1,player2,time_service);
	player1->update(event_manager->isKeyPressed(Keyboard::W),
		event_manager->isKeyPressed(Keyboard::S), time_service);
	player2->update(event_manager->isKeyPressed(Keyboard::Up),
		event_manager->isKeyPressed(Keyboard::Down), time_service);
	updateScore();       // Check for scoring events
	uiService->update(); // Update score display
}

void Gameplay::GameplayManager::updateScore()
{
	// Left side out - Player 2 scores!
	if (ball->isLeftCollisionOccurred()) {
		uiService->incrementPlayer2Score();
		ball->updateLeftCollisionState(false);
		resetPlayers();  // You'll implement it next
	}

	// Right side out - Player 1 scores!
	if (ball->isRightCollisionOccurred()) {
		uiService->incrementPlayer1Score();
		ball->updateRightCollisionState(false);
		resetPlayers();  // You'll implement it next
	}
}

void GameplayManager::resetPlayers() {
	player1->reset(player1_position_x, player1_position_y);
	player2->reset(player2_postion_x, player2_postion_y);
}

void GameplayManager::render(RenderWindow* game_window)
{
	boundary->render(game_window);
	ball->render(game_window);
	player1->render(game_window);
	player2->render(game_window);
	uiService->render(game_window);
}

GameplayManager::GameplayManager(EventManager* eventManager)
{
	time_service = new TimeService();
	time_service->initialize();// Start our time tracking
	//previous code
	initialize();
	event_manager = eventManager;
}

