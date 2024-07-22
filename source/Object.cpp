#include "Object.h"

Object::Object(sf::Vector2<float> position, sf::Vector2<float> size, sf::Color color)
  : position(position), m_window(nullptr)
{
  this->fillColor = color;

  this->width = size.x;
  this->height = size.y;
}

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
  float minDist = 100000000.0f;

  float distance = (a->getX() + a->width) - b->getX();
  if (std::abs(distance) < minDist) {
    minDist = std::abs(distance);
    mtv.x = distance;
    mtv.y = 0;
  }

  distance = (a->getY() + a->height) - b->getY();
  if (std::abs(distance) < minDist) {
    minDist = std::abs(distance);
    mtv.x = 0;
    mtv.y = distance;
  }

  distance = a->getX() - (b->getX() + b->width);
  if (std::abs(distance) < minDist) {
    minDist = std::abs(distance);
    mtv.x = distance;
    mtv.y = 0;
  }

  distance = a->getY() - (b->getY() + b->height);
  if (std::abs(distance) < minDist) {
    mtv.x = 0;
    mtv.y = distance;
  }

  mtv.x *= -1;
  mtv.y *= -1;

  return mtv;
}
