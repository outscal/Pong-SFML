#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
using namespace sf;

namespace GamePlay {

	class Ball {
	private:
		CircleShape ball_circleShape_sprite;
		const float radius = 10.f;
		const float xPos = 250;
		const float yPos = 100;

		float ball_speed = 0.5f;
		Vector2f ball_velocity = Vector2f(ball_speed, 1);
		
		Texture ball_texture;
		String ball_texture_path = "Assets/Textures/Ball.png";

		Sprite ball_sprite;

		float ball_sprite_x_scale = 0.08f, ball_sprite_y_scale= 0.08f;

		float top_boundary=25.f;
		float bottom_boundary=970.f;
		float left_boundary = 25.f;
		float right_boundary = 1950.f;

		float center_x_pos = 975;
		float center_y_pos = 485;
		

		void LoadTexture();
		void InitializeVariables();
		void HandleBoundaryCollision();
		void HandleOutOfBoundsCollision();
		void Reset();
		void OnCollision(Paddle* left_paddle, Paddle* right_paddle);

	public:
		Ball();
		void Update(Paddle* left_paddle, Paddle* right_paddle);
		void Render(RenderWindow* gameWindow);
		void Move();
		void HandlePaddleCollision(Paddle* left_paddle, Paddle* right_paddle);

	};
}
