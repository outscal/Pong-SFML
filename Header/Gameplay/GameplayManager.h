#pragma once
#include "Paddle/Paddle.h"
#include "Ball/Ball.h"
#include "Boundary/Boundary.h"
#include "../../Header/Event/EventManager.h"

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

		void initialize();

	public:
		GameplayManager(EventManager* manager);
		//GameplayManager();
		void update();
		void render(RenderWindow* game_window);
		

	};

}