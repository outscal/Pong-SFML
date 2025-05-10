#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Core {

	class GameWindowManager {
	private:

		int game_Window_Width = 1280;
		int game_Window_height = 720;
		std::string game_Title = "Pong-SFML";

		RenderWindow* game_Window;

		void CreateGameWindow();
	public:

		void Initialize();
		RenderWindow* GetGameWindow();
		bool IsGameRunning();
		void Render();
		void ClearGameWindow();
		void DisplayGameWindow();

	};
}