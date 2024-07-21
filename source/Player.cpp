#include "Player.h"
#include "constants.h"

const float FRICTION = 0.95f;

Player::Player(sf::Vector2<float> position)
  : Object(position), velocity(0, 0)
{}

float Player::getXvel() const {
  return velocity.x;
}

float Player::getYvel() const {
  return velocity.y;
}

void Player::update()
{
  move();

  falling = true;

  velocity.x *= FRICTION;

  applyForce(GRAVITY);

  wallCollisions();
}

void Player::applyForce(sf::Vector2<float> force)
{
}

void Player::move()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    applyForce({-speed, 0});
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    applyForce({speed, 0});
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !falling)
  {
    applyForce({0, -height * 5});
  }
}

void Player::wallCollisions()
{
  if (position.x < 0)
  {
    position.x = 0;
    velocity.x = 0;
  }

  if (position.x + width > WINDOW_WIDTH)
  {
    position.x = WINDOW_WIDTH - width;
    velocity.x = 0;
  }

  if (position.y < 0)
  {
    position.y = 0;
    velocity.y = 0;
  }

  if (position.y + height > WINDOW_HEIGHT)
  {
    position.y = WINDOW_HEIGHT - height;
    velocity.y = 0;
    falling = false;
  }
}

void Player::resolveCollisions(const Object *a, const Object *b) {
  if (colliding(a, b)) {
    sf::Vector2<float> mtv = getMtv(a, b);

    float xVel = a->getXvel();
    float yVel = a->getYvel();

    position.x += mtv.x;
    position.y += mtv.y;

    if ( mtv.y > 0) {
      yVel = 0;
    }

    if (mtv.y < 0) {
      falling = false;
      yVel = 0;

    }

    if (mtv.x > 0) {
      xVel = 0;
    }

    if (mtv.x < 0) {
      xVel = 0;
    }
  }
}
