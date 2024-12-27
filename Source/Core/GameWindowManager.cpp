#include "../../Header/Core/GameWindowManager.h"

using namespace Core;

void Core::GameWindowManager::createGameWindow()
{
	// Create the window with specified dimensions and title
	game_window->create(VideoMode::getDesktopMode(), game_title, Style::Fullscreen);
}

void Core::GameWindowManager::initialize()
{
	// Allocate memory for the render window object
	game_window = new RenderWindow();
	// Set up the window with configured properties
	createGameWindow();
}

RenderWindow* Core::GameWindowManager::getGameWindow()
{
	return game_window;
}

bool Core::GameWindowManager::isGameRunning()
{
	// Return true if window is open, false if closed
	return game_window->isOpen();
}

void Core::GameWindowManager::clearWindow()
{
	game_window->clear();
}

void Core::GameWindowManager::displayWindow()
{
	return game_window->display();
}

//void Core::GameWindowManager::render()
//{
//	// Clear window with orange color (R:200, G:50, B:50, A:255)
//	game_window->clear(sf::Color(200, 50, 50, 255));
//
//	//draw shapes, sprites, etc 
//
//// Display the changes
//	game_window->display();
//}
