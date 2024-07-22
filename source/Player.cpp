#include "Player.h"
#include "constants.h"

const float FRICTION = 0.95f;

Player::Player(sf::Vector2<float> position, sf::Vector2<float> size, sf::Color color)
  : Object(position, size, color), velocity(0, 0)
{
  this->fillColor = color;

  this->width = size.x;
  this->height = size.y;
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
  velocity += force * PHYSICS_DT;
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

  position += velocity;
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

    position.x += mtv.x;
    position.y += mtv.y;

    if (mtv.y > 0) {
      velocity.y = 0;
    }

    if (mtv.y < 0) {
      falling = false;
      velocity.y = 0;
    }

    if (mtv.x > 0) {
      velocity.x = 0;
    }

    if (mtv.x < 0) {
      velocity.x = 0;
    }
  }
}
