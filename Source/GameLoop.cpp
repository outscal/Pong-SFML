#include"../../Header/GameLoop.h"

void Core::GameLoop::Initialize()
{
	Window_Game_Manager = new GameWindowsManager();
	Event_Manager = new EventManager();

	Window_Game_Manager->Initialize();

}

void Core::GameLoop::PoolEvents()
{
	Event_Manager->PoolEvent(Window_Game_Manager->getgamewindow());

}

void Core::GameLoop::Update()
{
}

bool Core::GameLoop::IsGameRunning()
{
	return Window_Game_Manager->isGameRuning();
}

void Core::GameLoop::Render()
{
	Window_Game_Manager->clearGameWindow();
	Window_Game_Manager->displayGameWindow();
}
