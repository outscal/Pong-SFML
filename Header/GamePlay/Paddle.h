#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace GamePlay {

	class Paddle {

	private:
		RectangleShape paddle_Sprite;
		float width = 30;
		float height = 235;
		
		const float speed = 0.5f;
		float top_boundary = 10.f;
		float bottom_boundary = 980.f-height;

		void MovePaddle(bool up_key_pressed, bool down_key_pressed);
		void CreatePaddle(float x_pos, float y_pos);

	public:

		Paddle(float xPos, float yPos);

		void Reset(float x_pos, float y_pos);
		
		RectangleShape GetPaddleSprite();
		void Update(bool up_key_pressed, bool down_key_pressed);
		void Render(RenderWindow* game_Window);
	};
}
