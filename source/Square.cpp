#include "Square.h"
#include "constants.h"

const float FRICTION = 0.95f;

Square::Square(sf::Vector2<float> position)
  : Object(position), velocity(0, 0)
{}

float Square::getXvel() {
  return velocity.x;
}

float Square::getYvel() {
  return velocity.y;
}

void Square::update()
{
  move();

  falling = true;

  velocity.x *= FRICTION;

  applyForce(GRAVITY);

  position += velocity;

  wallCollisions();
}

void Square::applyForce(sf::Vector2<float> force)
{
  velocity += force * PHYSICS_DT;
}

void Square::move()
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

void Square::wallCollisions()
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
