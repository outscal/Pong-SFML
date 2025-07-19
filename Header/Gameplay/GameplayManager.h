#pragma once
#include "../../Header/Entities/Paddle.h"
#include "../../Header/Entities/Ball.h"
#include "../Event/EventManager.h"
#include "../../Header/Entities/Boundary.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/Core/UIService.h"	

namespace Gameplay
{
	class GameplayManager
	{
	private:

		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1210.0f;
		float player2_position_y = 300.0f;

		Paddle* player1_paddle;
		Paddle* player2_paddle;
		Ball* ball;
		Boundary* boundary;
		Core::UIService* ui_service;
		Utility::TimeService* time_service;
		Events::EventManager* event_manager;
		void initialize();
	public:
		GameplayManager(Events::EventManager* manager);
		void render(sf::RenderWindow* game_window);
		void update();

	};
} // namespace Gameplay