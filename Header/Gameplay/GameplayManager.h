#pragma once

#include "Paddle.h"
#include "Ball.h"
#include "../Event/EventManager.h"
#include "../Utility/TimeManager.h"
#include "../UI/UIService.h"
#include "Boundary.h"

using namespace Eventmanager;
using namespace Utility;

namespace Gameplay
{
	class GameplayManager
	{
	private:
		float player1_position_x = 30.0f;
		float player1_position_y = 290.0f;	
		float player2_position_x = 1230.0f;
		float player2_postion_y = 290.0f;

		Boundary* boundary;
		EventManager* event_manager;
		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		TimeManager* time_manager;
		UIService* ui_service = new UIService();
		void UpdateScore();
		void resetPlayers();

		void initialize();

	public:
		GameplayManager(EventManager* manager);
		//GameplayManager();
		void update();
		void render(RenderWindow* game_window);

	};
}

