#pragma once
#include<SFML/Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;
namespace GameManager {
	class GameWindowsManager {
	private:
		RenderWindow* gameWindow;
		float height=1080;
		float width= 1920;
		string gameTile= "SFML-Pong!";
	public:
		void Initialize();
		/*void render();*/
		RenderWindow* getgamewindow();
		bool isGameRuning();
		void createGamewindows();
		void clearGameWindow();
		void displayGameWindow();
		
	};
}
