#include "../../Header/Gameplay/Ball.h"

using namespace Gameplay;

void Ball::loadTexture()
{
	if (!pong_ball_texture.loadFromFile(texture_path))
		throw std::runtime_error("Failed to load ball texture.");
}

void Ball::initializeVariables()
{
	pong_ball_sprite.setTexture(pong_ball_texture);
	pong_ball_sprite.setScale(scale_x, scale_y);
	pong_ball_sprite.setPosition(position_x, position_y);
}

void Ball::handlePaddleCollision(Paddle* p1, Paddle* p2)
{
	const RectangleShape& p1Paddle = p1->getPaddleSprite();
	const RectangleShape& p2Paddle = p2->getPaddleSprite();

	FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
	FloatRect p1PaddleBoundary = p1Paddle.getGlobalBounds();
	FloatRect p2PaddleBoundary = p2Paddle.getGlobalBounds();

	if (ball_bounds.intersects(p1PaddleBoundary) && velocity.x < 0)
		velocity.x = -velocity.x;
	if (ball_bounds.intersects(p2PaddleBoundary) && velocity.x > 0)
		velocity.x = -velocity.x;
}

void Ball::handleBoundaryCollision()
{
	FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
	if (ball_bounds.top <= top_boundary && velocity.y < 0 || ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0)
		velocity.y = -velocity.y;
}

void Ball::handleScoreCollisions()
{
	FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
	if (ball_bounds.left <= left_boundary)
	{
		updateLeftCollision(true);
		reset();
	}
	else if (ball_bounds.left + ball_bounds.width >= right_boundary)
	{
		updateRightCollision(true);
		reset();
	}
}

void Ball::reset()
{
	pong_ball_sprite.setPosition(position_x, position_y);
	velocity = Vector2f(ball_speed, ball_speed);
}

Ball::Ball()
{
	loadTexture();
	initializeVariables();
}

bool Gameplay::Ball::isLeftCollisionOccurred()
{
	return had_left_collision;
}

void Gameplay::Ball::updateLeftCollision(bool value)
{
	had_left_collision = value;
}

bool Gameplay::Ball::isRightCollisionOccurred()
{
	return had_right_collision;
}

void Gameplay::Ball::updateRightCollision(bool value)
{
	had_right_collision = value;
}

void Ball::update(Paddle* p1, Paddle* p2)
{
	move();
	handlePaddleCollision(p1,p2);
	handleBoundaryCollision();
	handleScoreCollisions();
}

void Ball::render(RenderWindow* game_window)
{
	game_window->draw(pong_ball_sprite);
}

void Ball::move()
{
	pong_ball_sprite.move(velocity);
}
