#include "../../Header/Gameplay/Paddle/Paddle.h"

using namespace Gameplay;
using namespace Utility;

Paddle::Paddle(float position_x, float position_y)
{
    paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
    paddle_sprite.setPosition(position_x, position_y);
}

void Paddle::render(RenderWindow* game_window)
{
    game_window->draw(paddle_sprite);
}

RectangleShape Paddle::getPaddleSprite()
{
    return paddle_sprite;
}

void Paddle::reset(float position_x, float position_y)
{

}

void Paddle::createPaddle(float position_x, float Position_y)
{

}

void Paddle::movePaddle(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service)
{
	if (move_up_key_pressed && paddle_sprite.getPosition().y > top_boundary)
	{
		paddle_sprite.move(0, -paddleSpeed*time_service->getDeltaTime() * speedMultiplier);
	}
	if (move_down_key_pressed && paddle_sprite.getPosition().y + paddle_sprite.getSize().y < bottom_boundary)
	{
		paddle_sprite.move(0, paddleSpeed * time_service->getDeltaTime() * speedMultiplier);
	}
}

void Paddle::update(bool move_up_key_pressed, bool move_down_key_pressed,TimeService* timeService)
{
    movePaddle(move_up_key_pressed, move_down_key_pressed,timeService);
}