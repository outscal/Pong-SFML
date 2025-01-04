#include"../../Header/GameLoop.h"
using namespace Core;

int main() {

	GameLoop* gameLoop;
	gameLoop = new GameLoop();

	gameLoop->Initialize();

	while (gameLoop->IsGameRunning()) {

		gameLoop->PoolEvents();
		gameLoop->Update();

		gameLoop->Render();

		
	}



	//GameWindowsManager* gamewindowManager;
	//gamewindowManager = new GameWindowsManager();
	//EventManager event;

	//gamewindowManager->Initialize();

	//while(gamewindowManager->isGameRuning()){

	//	event.PoolEvent(gamewindowManager->getgamewindow());
	//	event.IsLeftButtonPressed();

	//	gamewindowManager->render();
	//}
	//delete(gamewindowManager);
	return 0;
}