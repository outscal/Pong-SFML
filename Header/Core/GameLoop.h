#pragma once
#include < SFML/Graphics.hpp>
#include "D:\unity\repos\SFML-Pong\Header\Core\GameWindowManager.h"
#include "D:\unity\repos\SFML-Pong\Header\Event\EventManager.h"
#include "D:\unity\repos\SFML-Pong\Header\GamePlay\GamePlayManager.h"

using namespace sf;
using namespace Core;
using namespace MyEvent;
using namespace std;
using namespace GamePlay;

namespace Core {

	class GameLoop {

	private:
		GameWindowManager* game_Window_Manager;
		EventManager* event_Manager;
		GamePlayManager* gameplayManager;

	public:

		void Initialize();
		void Update();
		bool IsGameRunning();
		void Render();
		void PollEvent();



	};


}