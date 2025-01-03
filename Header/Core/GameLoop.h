#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Gameplay/Ball/Ball.h"

using namespace sf;
using namespace Core;
using namespace Event;
using namespace std;
using namespace Gameplay;

namespace Core
{
	class GameLoop
	{
		private:
			GameWindowManager* game_window_manager;
			EventManager* event_manager;
			GameplayManager* gameplay_manager;

		public:
			void initialize();
			bool isGameRunning();
			void pollEvent();
			void update();
			void render();
	};
}
