#include "../../Header/GameLoop/GameLoop.h"
#include "../../Header/Sound/SoundManager.h"

using namespace Sound;

namespace Core
{
    void GameLoop::initialize() {
        SoundManager::Initialize();
        SoundManager::PlayBackgroundMusic();// Let the music begin!
        game_window_manager = new GameWindowManager();
        event_manager = new EventManager();
        game_window_manager->initialize();
        gameplay_manager = new GameplayManager(event_manager);
    }

    bool GameLoop::isGameRunning() {
        return game_window_manager->isGameRunning();
    }

    void GameLoop::pollEvent() {
        event_manager->pollEvents(game_window_manager->getGameWindow());
    }

    void GameLoop::update() {
        gameplay_manager->update();
    }

    void GameLoop::render() {
        game_window_manager->clearGameWindow();
        gameplay_manager->render(game_window_manager->getGameWindow());
        game_window_manager->displayGameWindow();
    }
}