#include "GamePlayManager.h"

namespace GamePlay {



	GamePlayManager::GamePlayManager(EventManager* event_manager)
	{
		this->event_manager = event_manager;
		boundary = new Boundary();
		Initialize();
	}

	void GamePlayManager::Update()
	{
		ball->Update(leftPaddle, rightPaddle);
		leftPaddle->Update(event_manager->IsKeyPressed(sf::Keyboard::W),event_manager
		->IsKeyPressed(sf::Keyboard::S));
		rightPaddle->Update(event_manager->IsKeyPressed(sf::Keyboard::Up), event_manager
			->IsKeyPressed(sf::Keyboard::Down));
	}

	void GamePlay::GamePlayManager::Initialize()
	{
		ball = new Ball();

		leftPaddle = new Paddle(leftPaddle_X_Pos, leftPaddle_Y_Pos);
		rightPaddle = new Paddle(rightPaddle_X_Pos, rightPaddle_Y_Pos);


	}

	void GamePlayManager::Render(RenderWindow* game_Window)
	{
		boundary->Render(game_Window);
		leftPaddle->Render(game_Window);
		rightPaddle->Render(game_Window);
		ball->Render(game_Window);
	}


	

	

}

