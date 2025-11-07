#include "../../Header/Gameplay/Paddle/Paddle.h"

namespace Gameplay {

    Paddle::Paddle() {
        loadTexture();
    }
    RectangleShape& Paddle::getPaddleSprite()
    {
        return paddle_sprite;
    }

    Paddle::Paddle(float position_x, float position_y) {
        loadTexture();
        paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
        paddle_sprite.setPosition(position_x, position_y);
    }

    void Paddle::update(bool move_up, bool move_down) {
        Vector2f position = paddle_sprite.getPosition();
        if (move_up) position.y -= 5.f;
        if (move_down) position.y += 5.f;
        paddle_sprite.setPosition(position);
    }

    void Paddle::render(RenderWindow* game_window) {
        game_window->draw(paddle_sprite);
    }

    void Paddle::loadTexture() {
        if (Paddle_texture.loadFromFile(texture_path)) {
            paddle_sprite.setTexture(&Paddle_texture);
        }
    }
}
