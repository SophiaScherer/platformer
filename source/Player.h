#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include "Object.h"

class Player : public Object {
public:
  explicit Player(sf::Vector2<float> position, sf::Vector2<float> size, sf::Color color);

  void update() override;

  void applyForce(sf::Vector2<float> force);

  void move();

  void wallCollisions();

  void resolveCollisions(const Object *a, const Object *b);

private:
  sf::Vector2<float> velocity;

  float speed = 10.25;

  bool falling = true;
};


#endif //PLATFORMER_PLAYER_H
