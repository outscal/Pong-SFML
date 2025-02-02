#pragma once
#include < SFML/Graphics.hpp>
#include "D:\unity\repos\SFML-Pong\Header\GameWindowManager.h"
#include "D:\unity\repos\SFML-Pong\Header\Event\EventManager.h"

using namespace sf;
using namespace Core;
using namespace MyEvent;
using namespace std;

namespace Core {

	class GameLoop {

	private:
		GameWindowManager* game_Window_Manager;
		EventManager* event_Manager;

	public:

		void Initialize();
		void Update();
		bool IsGameRunning();
		void Render();
		void PollEvent();



	};


}