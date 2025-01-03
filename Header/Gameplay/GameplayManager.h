#pragma once
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Gameplay/Ball/Ball.h"
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/Boundary/Boundary.h"
#include"../../Header/Utility/TimeService.h"

using namespace Event;
using namespace Utility;


namespace Gameplay
{
	class GameplayManager
	{

	private:
		EventManager* event_manager;
		TimeService* time_service;

		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_postion_x = 1210.0f;
		float player2_postion_y = 300.0f;

		Boundary* boundary = new Boundary;
		Ball* ball = new Ball();
		Paddle* player1 = new Paddle(player1_position_x, player1_position_y);
		Paddle* player2 = new Paddle(player2_postion_x, player2_postion_y);

	public:
		GameplayManager(EventManager* manager);

		
		void update();
		void render(RenderWindow* game_window);
	};
}