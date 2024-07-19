#include "Object.h"

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

float Object::getWidth() const {
  return width;
}

float Object::getHeight() const {
  return height;
}

float Object::getX() const {
  return position.x;
}

float Object::getY() const {
  return position.y;
}

bool Object::colliding(Object* a, Object* b) {
  return !(
    a->getX() + a->width < b->getX() || //left
    a->getY() + a->height < b->getY() || //top
    a->getX() > b->getX() + b->width || //right
    a->getY() > b->getY() + b->height //bottom
  );
}

