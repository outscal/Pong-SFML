#include "D:\unity\repos\SFML-Pong\Header\GamePlay\Ball.h"
#include <iostream>
using namespace std;

namespace GamePlay {
	void Ball::LoadTexture()
	{
		if (!ball_texture.loadFromFile(ball_texture_path))
		{
			throw std::runtime_error("unable to load ball texture");
		}
	}
	void Ball::InitializeVariables()
	{
		ball_sprite.setTexture(ball_texture);
		ball_sprite.setScale(ball_sprite_x_scale, ball_sprite_y_scale);
		ball_sprite.setPosition(xPos, yPos);
	}
	void Ball::HandleBoundaryCollision()
	{
		FloatRect ball_boundary = ball_sprite.getGlobalBounds();


		if ((ball_boundary.top <= top_boundary && ball_velocity.y < 0)) {

			ball_velocity.y = -ball_velocity.y;
			cout << endl << "top boundary collision detected"<<endl;
		}
		else if (ball_boundary.top + ball_boundary.height >= bottom_boundary && ball_velocity.y > 0) {
			ball_velocity.y = -ball_velocity.y;
			cout << endl << "bottom boundary collision detected";
		}
	}


	void Ball::HandleOutOfBoundsCollision()
	{

		FloatRect ball_boundary= ball_sprite.getGlobalBounds();

		if (ball_boundary.left <= left_boundary)
		{
			Reset();
			cout << endl << "left boundary hit";
		}
		if (ball_boundary.left + ball_boundary.width >= right_boundary)
		{
			Reset();
			cout << endl << "right boundary hit";
		}

	}

	void Ball::Reset()
	{
		ball_sprite.setPosition(center_x_pos, center_y_pos);
		ball_velocity = Vector2f(ball_speed, ball_speed);
	}

	void Ball::OnCollision(Paddle* left_paddle, Paddle* right_paddle)
	{
		HandleBoundaryCollision();
		HandlePaddleCollision(left_paddle, right_paddle);
		HandleOutOfBoundsCollision();
		
	}


	Ball::Ball()
	{
		/*ball_circleShape_sprite.setRadius(radius);
		ball_circleShape_sprite.setPosition(xPos, yPos);*/
		LoadTexture();
		InitializeVariables();

	}
	void Ball::Update(Paddle* left_paddle, Paddle* right_paddle)
	{
		Move();
		OnCollision(left_paddle, right_paddle);
		
	}
	void Ball::Render(RenderWindow* gameWindow)
	{
		gameWindow->draw(ball_sprite);
	}
	void Ball::Move()
	{
		ball_sprite.move(ball_velocity);
	}
	void Ball::HandlePaddleCollision(Paddle* left_paddle, Paddle* right_paddle)
	{
		const RectangleShape& left_paddle_sprite = left_paddle->GetPaddleSprite();
		const RectangleShape& right_paddle_sprite = right_paddle->GetPaddleSprite();
		FloatRect ball_bounds = ball_sprite.getGlobalBounds();
		FloatRect left_paddle_bounds = left_paddle_sprite.getGlobalBounds();
		FloatRect right_paddle_bounds = right_paddle_sprite.getGlobalBounds();

		if (ball_bounds.intersects(left_paddle_bounds) && ball_velocity.x < 0.f) {

			ball_velocity.x =-ball_velocity.x;

		}
		if (ball_bounds.intersects(right_paddle_bounds) && ball_velocity.x > 0.f)
		{
			ball_velocity.x = -ball_velocity.x;
		}
	}
}
