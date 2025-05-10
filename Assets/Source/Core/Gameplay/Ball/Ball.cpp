#include "D:\Unity Projects 2024\Co-Op Snake 2D\Pong-SFML\Assets\Header\Gameplay\Ball\Ball.h"
namespace Gameplay
{
	Ball::Ball()
	{


		loadTexture();
		initializeVariables();
	}
	void Ball::handlePaddlcollision(Paddle* player1, Paddle* player2)
	{
		const RectangleShape& player1Paddle = player1->getPaddleSprite();
		const RectangleShape& player2Paddle = player2->getPaddleSprite();


		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect player1_bounds = player1Paddle.getGlobalBounds();
		FloatRect player2_bounds = player2Paddle.getGlobalBounds();

		if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)
		{
			velocity.x = -velocity.x; 
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}
		if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
		{
			velocity.x = -velocity.x; 
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}

	}
	void Ball::handleBoudaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
			(ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
		{
			velocity.y = -velocity.y; 
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
			
		}
	}
	void Ball::handleOutofBoundCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
		{
			updateLeftCollisionState(true);
			reset();      
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			updateRightCollisionState(true);
			reset();        // Player 1 scores!
		}
	}
	void Ball::reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}
	
	void Ball::initializeVariables()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);

		pong_ball_sprite.setPosition(position_x, position_y);
	}
	void Ball::move(TimeService* time_service)
	{
		updateDelayTime(time_service->getDeltatime());
		pong_ball_sprite.move(velocity * time_service->getDeltatime() * speedMultiplier);
	}
	void Ball::updateDelayTime(float deltaTime)
	{

		if (current_state == BallState::Idle)
		{
			elapsed_delay_time += deltaTime;
			if (elapsed_delay_time >= delay_duration)
			{
				current_state = BallState::Moving;
			}
			else
			{
				return;
			}
		}
	}
	void Ball::loadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw std::runtime_error("Failed to load ball texture!");
		}
	}

	void Ball::update(Paddle* player1, Paddle* player2, TimeService* timeService)
	{
		move(timeService);
		onCollision(player1, player2);
	}
	void Ball::onCollision(Paddle* player1, Paddle* player2)
	{
		handleBoudaryCollision();
		handlePaddlcollision(player1, player2);
		handleOutofBoundCollision();
	}

	bool Ball::isLeftCollisionOccurred()
	{
		return had_left_collison;
	}

	void Ball::updateLeftCollisionState(bool value)
	{
		had_left_collison = value;
	}

	bool Ball::isRightCollisionOccurred()
	{
		return had_right_collison;
	}

	void Ball::updateRightCollisionState(bool value)
	{
		had_right_collison = value;
	}

	

	void Ball::render(RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}
	

}
