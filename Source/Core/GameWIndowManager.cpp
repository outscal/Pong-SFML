#include "/Users/MY PC/source/repos/Pong-SFML/Pong-SFML/Header/Core/GameWindowManager.h"


namespace Core {
	void GameWindowManager::initialize() {
		//allocate memory for the render window object
		game_window = new RenderWindow();
		// set up window with configured properties
		createGameWindow();
	}

	void GameWindowManager::createGameWindow() {
		//create the window with specified dimensions and title
		game_window->create(VideoMode(game_window_width, game_window_height), game_title);
	}

	bool GameWindowManager::render() {
		//this will handle the drawing operations
	}

	RenderWindow* GameWindowManager::getGameWindow() {
		return game_window;
	}
}