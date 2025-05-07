#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/Sound/SoundManager.h"

using namespace sf;
using namespace std;
using namespace Sound;

namespace Gameplay {
	enum class BallState {
		Idel,
		Moving
	};
	class Ball {
	private:
		Texture pong_ball_texture;
		Sprite pong_ball_sprite;

		string texture_path = "Assets/Textures/Ball.png";
		CircleShape ball_sprite;

		const float scale_x = 0.02f;
		const float scale_y = 0.02f;

		const float radius = 10.0f;
		const float position_x = 615.0f;
		const float position_y = 335.0f;

		float ball_speed = 100.0f;
		Vector2f velocity = Vector2f(ball_speed, ball_speed);

		const float top_boundary = 20.0f;
		const float bottom_boundary = 700.0f;

		const float left_boundary = 0.0f;
		const float right_boundary = 1280.0f;

		//Center Position
		const float center_position_x = 615.0f;
		const float center_position_y = 325.0f;

		int speed_multiplier = 10;

		float delay_duration = .1f;
		float elapsed_delay_time = 0.0f;
		
		bool had_left_collision = false;
		bool had_right_collision = false;

		BallState current_state;

		void loadTexture();
		void initializeVariables();
		void move(TimeService* time_service);
		void onCollision(Paddle* player1, Paddle* player2);
		void updateDelayTime(float delta_time);

	public:
		Ball();
		bool isLeftCollisionOccurred();
		void updateLeftCollisionState(bool value);

		bool isRightCollisionOccurred();
		void updateRightCollisionState(bool value);

		void handlePaddleCollision(Paddle* player1, Paddle* player2);
		void handleBoundaryCollision();
		void handleOutofBoundCollision();
		void reset();
		void update(Paddle* player1, Paddle* player2,TimeService* time_server);
		void render(RenderWindow* game_window);

	};
}