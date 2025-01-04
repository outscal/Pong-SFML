#pragma once
#include"SFML/Graphics.hpp"
#include"../../Header/GameWindowManager.h"
#include"../../Header/EventManager.h"
using namespace sf;
using namespace Event;
using namespace GameManager;
namespace Core {
	class GameLoop {
	private:
		GameWindowsManager* Window_Game_Manager;
		EventManager* Event_Manager;
	public:
		void Initialize();
		void PoolEvents();
		void Update();
		bool IsGameRunning();
		void Render();
	
	};
}