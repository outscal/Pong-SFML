#include "../../Header/Gameplay/Ball/Ball.h";

namespace Gameplay {
	Ball::Ball()
	{
		ball_sprite.setRadius(radius);
		ball_sprite.setPosition(position_x, position_y);
		loadTexture();
		initializeVariables();
	}

	void Ball::render(RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}
	void Ball::loadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw std::runtime_error("Failed to load ball texture!");
		}
	}
	void Ball::initializeVariables()
	{
		
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(position_x, position_y);


		current_state = BallState::Idel;
	}
	void Ball::move(TimeService* time_service)
	{
		updateDelayTime(time_service->getDeltaTime());
		pong_ball_sprite.move(velocity * (time_service->getDeltaTime() * speed_multiplier));
	}
	void Ball::update(Paddle* player1, Paddle* player2, TimeService* time_server)
	{
		move(time_server);
		onCollision(player1, player2);
	}
	void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		//to get our sprites
		const RectangleShape& player1Paddle = player1->getPaddleSprite();
		const RectangleShape& player2Paddle = player2->getPaddleSprite();

		//check their bounds
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect player1_bounds = player1Paddle.getGlobalBounds();
		FloatRect player2_bounds = player2Paddle.getGlobalBounds();

		//handle collision
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
	void Ball::handleBoundaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) || (ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
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
			reset(); //player 2 scores..
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			updateRightCollisionState(true);
			reset(); //player 2 scores..
		}
	}
	void Ball::reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}
	void Ball::onCollision(Paddle* player1, Paddle* player2)
	{
		handleBoundaryCollision();
		handlePaddleCollision(player1, player2);
		handleOutofBoundCollision();
	}
	void Ball::updateDelayTime(float deltaTime)
	{
		if (current_state == BallState::Idel) {
			elapsed_delay_time += deltaTime;

			if (elapsed_delay_time >= delay_duration)
			{
				current_state = BallState::Moving;
			}
			else {
				return;
			}
		}
	}
	bool Ball::isLeftCollisionOccurred() {
		return had_left_collision;
	}
	bool Ball::isRightCollisionOccurred()
	{
		return had_right_collision;
	}
	void Ball::updateLeftCollisionState(bool value) {
		had_left_collision = value;
	}
	void Ball::updateRightCollisionState(bool value) {
		had_right_collision = value;
	}
	
}
