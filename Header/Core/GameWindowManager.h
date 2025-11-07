
#pragma once
#include <SFML/Graphics.hpp>

namespace Core
{
    class GameWindowManager
    {
    private:
        sf::RenderWindow game_window;
        int game_window_width = 1280;
        int game_window_height = 720;
        std::string game_title = "PING PONG";

    public:
        GameWindowManager();

        void initialize();
        bool isGameRunning();
        sf::RenderWindow* getGameWindow();
        void clearGameWindow();
        void displayGameWindow();
    };
}
