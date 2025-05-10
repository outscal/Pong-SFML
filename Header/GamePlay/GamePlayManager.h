#pragma once
#include <SFML/Graphics.hpp>

#include "Ball.h"
#include "Paddle.h"
#include "D:\unity\repos\SFML-Pong\Header\Event\EventManager.h"
#include "D:\unity\repos\SFML-Pong\Header\GamePlay\Boundry\Boundary.h"

using namespace MyEvent;
namespace GamePlay {

	class GamePlayManager {

	private:
		float leftPaddle_X_Pos = 35.f;
		float leftPaddle_Y_Pos = 450.f;
		float rightPaddle_X_Pos = 1850.f;
		float rightPaddle_Y_Pos = 450.f;

		Ball* ball;
		Paddle* leftPaddle;
		Paddle* rightPaddle;

		EventManager* event_manager;
		Boundary* boundary;
		void Initialize();

	public:

		GamePlayManager(EventManager* event_manager);
		void Update();
		void Render(RenderWindow* game_Window);
	};
}