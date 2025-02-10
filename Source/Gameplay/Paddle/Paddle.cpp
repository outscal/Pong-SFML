#include "../../Header/Gameplay/Paddle/Paddle.h"

namespace Gameplay {
	Paddle::Paddle(float position_x, float position_y)
	{
		paddleSprite.setSize(sf::Vector2f(paddle_width, paddle_height));
		paddleSprite.setPosition(position_x, position_y);
	}
	void Paddle::update()
	{
	}
	void Paddle::render(RenderWindow* game_window)
	{
		game_window->draw(paddleSprite);
	}
}