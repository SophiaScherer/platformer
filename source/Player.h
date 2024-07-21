#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include "Object.h"

class Player : public Object {
public:
  explicit Player(sf::Vector2<float> position);

  float getXvel();
  float getYvel();

  void update() override;

  void applyForce(sf::Vector2<float> force);

  void move();

  void wallCollisions();

protected:
  sf::Vector2<float> velocity;

  float speed = 10.25;

  bool falling = true;
};


#endif //PLATFORMER_PLAYER_H
