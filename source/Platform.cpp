#include "Platform.h"

Platform::Platform(sf::Vector2<float> position, sf::Vector2<float> size, sf::Color color)
  : Object(position)
{
  this->fillColor = color;

  this->width = size.x;
  this->height = size.y;
}