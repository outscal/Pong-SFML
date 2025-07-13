#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

namespace Gameplay
{
	class Ball
	{
	private:

		Sprite pong_ball_sprite;
		const float scale_x = 0.2f; // 20% of original size
		const float scale_y = 0.2f; // 20% of original size
		float ball_speed = 0.5f;
		Vector2f velocity = Vector2f(ball_speed, ball_speed);
		RectangleShape paddle1;
		RectangleShape paddle2;
		const float top_boundary = 20.0f;
		const float bottom_boundary = 700.0f;
		const float left_boundary = 0.0f;
		const float right_boundary = 1280.0f;

		//Center Position
		const float center_position_x = 615.0f;
		const float center_position_y = 325.0f;
		Texture pong_ball_texture;
		const std::string texture_path = "Assets/Textures/Ball.png";
		const float radius = 10.0f;
		const float position_x = 615.0f;
		const float position_y = 335.0f;

		void loadTexture();
		void prepareSprite();
		void handlePaddleCollision();
		void move();
		void reset();
		void handleOutOfBoundsCollision();
		void onCollision();
	public:
		Ball(RectangleShape paddle1, RectangleShape paddle2);
		void handleBoudaryCollision();
		void update();
		void render(RenderWindow* game_window);

	};
}