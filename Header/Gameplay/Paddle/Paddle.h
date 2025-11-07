#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

namespace Gameplay 
{
     
    class Paddle 
    {
    private:
        RectangleShape paddle_sprite;

        const float paddle_width = 20.f;
        const float paddle_height = 100.f;

        float paddleSpeed = 0.8f;
        float topBoundary = 20.0f;
        float bottomBoundary = 700.0f;

        Texture Paddle_texture;
        string texture_path = "Assets/Textures/Paddle.png";

        void createPaddle(float position_x, float position_y);
        void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed);

    public:
        Paddle();
        Paddle(float position_x, float position_y);
        sf::RectangleShape& getPaddleSprite();
        void reset(float position_x, float position_y);

        void update(bool move_up, bool move_down);
        void render(RenderWindow* game_window);

    private:
        void loadTexture();
    };
}