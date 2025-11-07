
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"

using namespace sf;

int main() {
    Core::GameWindowManager gameWindowManager;
    gameWindowManager.initialize();

    GameEvent::EventManager eventManager;
    Gameplay::GameplayManager gameplayManager(&eventManager);

    while (gameWindowManager.isGameRunning()) {
        eventManager.pollEvents(gameWindowManager.getGameWindow());

        gameplayManager.update();

        gameWindowManager.clearGameWindow();
        gameplayManager.render(gameWindowManager.getGameWindow());
        gameWindowManager.displayGameWindow();
    }

    return 0;
}
