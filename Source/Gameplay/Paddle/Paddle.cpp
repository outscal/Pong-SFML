#include "../../Header/Gameplay/Paddle/Paddle.h"

namespace Gameplay {
	void Paddle::movePaddle(bool move_up_key_pressed, bool move_down_key_pressed)
	{
		if (move_up_key_pressed)
		{
			paddleSprite.move(0, -paddle_speed);
		}
		if (move_down_key_pressed)
		{
			paddleSprite.move(0, paddle_speed);
		}
	}
	Paddle::Paddle(float position_x, float position_y)
	{
		paddleSprite.setSize(sf::Vector2f(paddle_width, paddle_height));
		paddleSprite.setPosition(position_x, position_y);
	}
	void Paddle::update(bool move_up_key_pressed, bool move_down_key_pressed)
	{
		movePaddle(move_up_key_pressed, move_down_key_pressed);
	}
	void Paddle::render(RenderWindow* game_window)
	{
		game_window->draw(paddleSprite);
	}
}