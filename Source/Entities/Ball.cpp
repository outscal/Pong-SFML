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
	void Ball::handlePaddleCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect player1_bounds = paddle1.getGlobalBounds();
		FloatRect player2_bounds = paddle2.getGlobalBounds();

		// 3. Handle collisions
		if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)
		{
			velocity.x = -velocity.x;  // Bounce!
		}
		if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
		{
			velocity.x = -velocity.x;  // Reverse horizontal direction
		}
	}
	void Ball::handleBoudaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
			(ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
		{
			velocity.y = -velocity.y;  // Reverse vertical direction
		}
	}
	void Ball::handleOutOfBoundsCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
		{
			reset();        // Player 2 scores!
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			reset();        // Player 1 scores!
		}
	}

	void Ball::reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}

	Ball::Ball(RectangleShape paddle1, RectangleShape paddle2)
	{
		this->paddle1 = paddle1;
		this->paddle2 = paddle2;
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

	void Ball::onCollision()
	{
		handleBoudaryCollision();
		handlePaddleCollision();
		handleOutOfBoundsCollision();
	}
}