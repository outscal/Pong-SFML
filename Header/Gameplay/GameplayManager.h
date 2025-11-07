
#pragma once
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Gameplay/Ball/Ball.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/Boundary/Boundary.h"

namespace Gameplay
{
    class GameplayManager {
    private:
        void initialize();
		

        float player1_position_x = 40.0f;
        float player1_position_y = 300.0f;

        float player2_position_x = 1210.0f;
        float player2_position_y = 300.0f;

        GameEvent::EventManager* event_manager;
		Boundary* boundary;
    public:
        
        void update();
        void render(sf::RenderWindow* game_window);
        GameplayManager(GameEvent::EventManager* manager);

        Ball* ball;
        Paddle* player1;
        Paddle* player2;
    };
}
