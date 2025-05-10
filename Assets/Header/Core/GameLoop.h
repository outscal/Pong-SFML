#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"
#include "D:\Unity Projects 2024\Co-Op Snake 2D\Pong-SFML\Assets\Header\Sound\SoundManager.h"
using namespace sf;
using namespace Core;
using namespace Event;
using namespace std;
using namespace Gameplay;
namespace Core
{
	class GameLoop
	{
	protected:
	    GameWindowManager* game_window_manager;
		EventManager* event_manager;
		GameplayManager* gameplay_manager;

		SoundManager* soundmanager;


	public:
		void initialize();
		bool isGameRunning();
		void pollEvent();
		void Update();
		void Render();
	};
}