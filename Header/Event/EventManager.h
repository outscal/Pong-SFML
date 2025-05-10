// EventManager.h
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

namespace Event {
    class EventManager {
    public:
        void pollEvents(RenderWindow* game_window); // Process all events
        bool isKeyPressed(sf::Keyboard::Key key);   // Check specific key
    };
}