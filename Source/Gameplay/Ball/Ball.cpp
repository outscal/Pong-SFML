#include "../../Header/Gameplay/Ball/Ball.h"
#include "../../Header/Gameplay/Paddle/Paddle.h"

using namespace Gameplay;

Ball::Ball()
{
    Ball_Shape.setRadius(radius);
    Ball_Shape.setPosition(640 , 360);
    Ball_Shape.setOrigin(radius, radius); 
    loadTexture();
    Ball_Shape.setTexture(&Pong_Ball_Texture);
}

void Ball::loadTexture()
{
    if (!Pong_Ball_Texture.loadFromFile(Texture_Path))
    {
        throw std::runtime_error("Failed to load ball texture from: " + Texture_Path);
    }
}

void Ball::update()
{
    Ball_Shape.move(velocity);

    if (Ball_Shape.getPosition().y - radius <= 20.0f || Ball_Shape.getPosition().y + radius >= 700.0f)
    {
        velocity.y *= -1;
    }

    if (Ball_Shape.getPosition().x < 0 || Ball_Shape.getPosition().x > 1280)
    {
        Ball_Shape.setPosition(640, 360);
        velocity = { 4.0f, 4.0f };
    }
}

void Ball::render(sf::RenderWindow* window)
{
    window->draw(Ball_Shape);
}

void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
{
    sf::FloatRect ballBounds = Ball_Shape.getGlobalBounds();
    sf::FloatRect player1Bounds = player1->getPaddleSprite().getGlobalBounds();
    sf::FloatRect player2Bounds = player2->getPaddleSprite().getGlobalBounds();

    if (ballBounds.intersects(player1Bounds) && velocity.x < 0)
    {
        float offset = (Ball_Shape.getPosition().y - player1->getPaddleSprite().getPosition().y) / player1->getPaddleSprite().getSize().y;
        velocity.x *= -1;
        velocity.y = 4.0f * (offset - 0.5f);
    }
    if (ballBounds.intersects(player2Bounds) && velocity.x > 0)
    {
        float offset = (Ball_Shape.getPosition().y - player2->getPaddleSprite().getPosition().y) / player2->getPaddleSprite().getSize().y;
        velocity.x *= -1;
        velocity.y = 4.0f * (offset - 0.5f);
    }
}
