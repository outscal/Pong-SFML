#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"
#include "../../Header/Sound/SoundManager.h"

using namespace sf;
using namespace Core;
using namespace CoustomEvent;
using namespace std;
using namespace Gameplay;
using namespace Sound;

namespace Core {

	class GameLoop
	{
	private:
		GameplayManager* gameplay_manager;
		GameWindowManager* game_window_manager;
		EventManager* event_manager;
		SoundManager* sound_manager;

	public:
		void initialize();

		bool isGameRunning();
		void update();
		void pollEvent();
		void render();
	};
}