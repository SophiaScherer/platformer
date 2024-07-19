#ifndef PLATFORMER_SQUARE_H
#define PLATFORMER_SQUARE_H

#include "Object.h"

class Square : public Object {
public:
  explicit Square(sf::Vector2<float> position);

  void update() override;

  void applyForce(sf::Vector2<float> force);

  void move();

  void wallCollisions();

  bool colliding(Object* a, Object* b);

private:
  sf::Vector2<float> velocity;

  float speed = 10.25;

  bool falling = true;
};


#endif //PLATFORMER_SQUARE_H