#pragma once
#include "Paddle/Paddle.h"
#include "Ball/Ball.h"
#include "../../Header/Event/EventManager.h"
#include"Boundary/Boundary.h"
#include "../../Header/Utility/TimeService.h"
#include "D:\Unity Projects 2024\Co-Op Snake 2D\Pong-SFML\Assets\Header\UI\UIService.h"
using namespace Event;
using namespace Utility;
using namespace UI;
namespace Gameplay
{
	class GameplayManager
	{
	protected:
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_postion_x = 1210.0f;
		float player2_postion_y = 300.0f;
		
		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		Boundary* boundary;
		TimeService* time_service;

		UIService* ui_service = new UIService;

		EventManager* event_manager;
		

		void initialize();

	public:
		void UpdateScore();
		void resetPlayers();
		GameplayManager(EventManager* manager);
		void update();
		void render(RenderWindow* game_window);
	};
}
