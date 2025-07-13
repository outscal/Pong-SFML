#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../Gameplay/GameplayManager.h"


namespace Core
{
	class GameLoop
	{
	private:
		Events::EventManager* eventManager;
		GameWindowManager* gameWindowManager;
		Gameplay::GameplayManager* gameplayManager;

	public:
		void initialize();
		bool isGameRunning();
		void pollEvents();
		void update();
		void render();
	};

}