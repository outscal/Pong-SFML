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

	public:
		Paddle(float position_x, float positon_y);
		void update();
		void render(RenderWindow* game_window);
	};
}