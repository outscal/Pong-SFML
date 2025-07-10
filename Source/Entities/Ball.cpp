#include "../../Header/Entities/Ball.h"

namespace Gameplay
{
	void Ball::loadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw std::runtime_error("Failed to load ball texture!");
		}
	}
	void Ball::prepareSprite()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(position_x, position_y);
	}
	Ball::Ball()
	{
		loadTexture();
		prepareSprite();
	}

	void Ball::render(RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}

	void Ball::move()
	{
		pong_ball_sprite.move(velocity);
	}

	void Ball::update()
	{
		move();
	}
}