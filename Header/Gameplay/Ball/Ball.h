#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace Gameplay
{
    class Paddle;
    class Ball
    {
    private:
        sf::CircleShape Ball_Shape;
        sf::Texture Pong_Ball_Texture;
        const std::string Texture_Path = "Assets/Textures/Ball.png";
        float radius = 15.0f;
        sf::Vector2f velocity = { 4.0f, 4.0f };
        void loadTexture();
        

    public:
        Ball();
        void update();
        void render(sf::RenderWindow* window);
        void handlePaddleCollision(Paddle* player1, Paddle* player2);
        
    };
}
