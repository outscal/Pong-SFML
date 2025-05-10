#pragma once
#include<SFML/Graphics.hpp>
#include "D:\Unity Projects 2024\Co-Op Snake 2D\Pong-SFML\Assets\Header\Gameplay\Paddle\Paddle.h"
#include "D:\Unity Projects 2024\Co-Op Snake 2D\Pong-SFML\Assets\Header\Utility\TimeService.h"
#include "D:\Unity Projects 2024\Co-Op Snake 2D\Pong-SFML\Assets\Header\Sound\SoundManager.h"
#include<iostream>
using namespace sf;
using namespace Utility;
using namespace Sound;
namespace Gameplay
{
	enum class BallState
	{
		Idle,
		Moving
	};
	class Ball
	{
	protected:

		Texture pong_ball_texture;
		Sprite pong_ball_sprite;

		std::string texture_path = "Assets/Textures/Ball.png";
		
		const float scale_x = 0.06f;
		const float scale_y = 0.06f;

		const float position_x = 615.0f;
		const float position_y = 335.0f;
	
		const float ball_speed =  5.0f;
		Vector2f velocity = Vector2f(ball_speed, ball_speed);
		
		const float top_boundary = 20.0f;
		const float bottom_boundary = 700.0f;

		const float left_boundary = 0.0f;
		const float right_boundary = 1280.0f;
		float speedMultiplier = 100.0f;
		//Center Position
		const float center_position_x = 615.0f;
		const float center_position_y = 325.0f;
		void loadTexture();
		void initializeVariables();
		BallState current_state = BallState::Idle;
		float delay_duration = 2.0f;
		float elapsed_delay_time = 0.0f;
		void move(TimeService* time_service);
		void updateDelayTime(float deltaTime);

		bool had_left_collison = false;
		bool had_right_collison = false;
		SoundManager* soundmanager;
	
	public:
		Ball();
		
		void handlePaddlcollision(Paddle* player1,Paddle* player2);
		void handleBoudaryCollision();
		void handleOutofBoundCollision();
		void reset();
		void onCollision(Paddle* player1, Paddle* player2);

		bool isLeftCollisionOccurred();
		void updateLeftCollisionState(bool value);

		bool isRightCollisionOccurred();
		void updateRightCollisionState(bool value);

		void update(Paddle* player1, Paddle* player2, TimeService* timeService);
		void render(RenderWindow* game_window);
	};
}