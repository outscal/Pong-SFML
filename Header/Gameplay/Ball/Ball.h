#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Gameplay {

	class Ball
	{
	private:
		Texture pong_ball_texture;
		const string texture_path = "Assets/Textures/Ball.png";
		Sprite pong_ball_sprite;
		const float scale_x = 0.1f;
		const float scale_y = 0.1f;

		const float position_x = 615.0f;
		const float position_y = 335.0f;

		float ballSpeed = 0.5f;
		Vector2f velocity = Vector2f(ballSpeed, ballSpeed);

		void loadTexture();
		void initializeVariables();

		void move();
	public:
		Ball();
		void update();
		void render(RenderWindow *game_window);
	};
}