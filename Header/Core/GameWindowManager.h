#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;
namespace Core
{
	class GameWindowManager
	{
	private:
		int gameWindowHeight = 720;
		int gameWindowWidth = 1280;
		std::string gameTitle = "SFML_Pong";

		RenderWindow* game_window;
		void createGameWindow();
	public:
		void initialize();
		RenderWindow* getGameWindow();
		bool isGameRunning();
		void clearGameWindow();
		void displayGameWindow();
	};

}