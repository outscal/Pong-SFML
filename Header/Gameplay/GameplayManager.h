#pragma once
#include "Paddle/Paddle.h"
#include "Ball/Ball.h"
#include "Boundary/Boundary.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/UI/UIService.h"

using namespace Utility;
using namespace CoustomEvent;

namespace Gameplay {
	class GameplayManager {
	private:
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1210.0f;
		float player2_position_y = 300.0f;

		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		EventManager* event_manager;
		Boundary* boundary;
		TimeService* time_service;
		UIService* ui_service;
		void initialize();

	public:
		GameplayManager(EventManager* manager);
		//GameplayManager();
		void UpdateScore();
		void resetPlayer();
		void update();
		void render(RenderWindow* game_window);
		

	};

}