#include "Object.h"
#include "Square.h"

Object::Object(sf::Vector2<float> position)
  : position(position), width(80), height(80), m_window(nullptr)
{}

void Object::update()
{}

void Object::bindWindow(sf::RenderWindow* window) {
  m_window = window;
}

void Object::draw() {
  sf::RectangleShape shape(sf::Vector2f(width, height));
  shape.setFillColor(fillColor);

  shape.setPosition(position);

  m_window->draw(shape);
}

float Object::getX() const {
  return position.x;
}

float Object::getY() const {
  return position.y;
}

bool Object::colliding(const Object* a, const Object* b) {
  return !(
    a->position.x + a->width < b->position.x || //left
    a->position.y + a->height < b->position.y || //top
    a->position.x > b->position.x + b->width || //right
    a->position.y > b->position.y + b->height //bottom
  );
}

sf::Vector2<float> Object::getMtv(const Object *a, const Object *b) {
  sf::Vector2<float> mtv(0, 0);
  float minDist = 100000000.;

  float distance = (a->getX() + a->width) - b->getY();
  if (abs(distance) < minDist) {
    minDist = abs(distance);
    mtv.x = distance;
    mtv.y = 0;
  }

  distance = (a->getY() + a->height) - b->getY();
  if (abs(distance) < minDist) {
    minDist = abs(distance);
    mtv.x = 0;
    mtv.y = distance;
  }

  distance = a->getX() - (b->getX() + b->width);
  if (abs(distance) < minDist) {
    minDist = abs(distance);
    mtv.x = distance;
    mtv.y = 0;
  }

  distance = a->getY() - (b->getY() + b->height);
  if (abs(distance) < minDist) {
    mtv.x = 0;
    mtv.y = distance;
  }

  mtv.x *= -1;
  mtv.y *= -1;

  return mtv;
}

//todo: move resolveCollisions to Square.cpp

void Object::resolveCollisions(const Object *a, const Object *b) {
  if (colliding(a, b)) {
    sf::Vector2<float> mtv = getMtv(a, b);

    a->position.x += mtv.x;
    a->position.y += mtv.y;

    if ( mtv.y > 0) {
      a->getYvel();
    }

    if (mtv.y < 0) {
      a.falling = false;
      a.yVel = 0;
    }

    if (mtv.x > 0) {
      a.xVel = 0;
    }

    if (mtv.x < 0) {
      a.xVel = 0;
    }
  }
}
