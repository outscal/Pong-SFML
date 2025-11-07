// GameLoop.h
#pragma once
#include "GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"

namespace Core
{
    class GameLoop {
    private:
        GameWindowManager* game_window_manager;
        GameEvent::EventManager* event_manager;
        Gameplay::GameplayManager* gameplay_manager;

    public:
        void initialize();
        void pollEvent();
        void update();
        void render();
        bool isGameRunning();
    };
}
