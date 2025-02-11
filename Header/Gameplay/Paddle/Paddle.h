#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Gameplay {
	class Paddle
	{
	private:
		RectangleShape paddleSprite;
		const float paddle_width = 20.0f;
		const float paddle_height = 140.0f;

		const float paddle_speed = 0.8f;

		float topBoundary = 20.0f;
		float bottomBoundary = 700.0f;

		void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed);

	public:
		Paddle(float position_x, float positon_y);

		RectangleShape getPaddleSprite();

		void update(bool move_up_key_pressed, bool move_down_key_pressed);
		void render(RenderWindow* game_window);
	};
}