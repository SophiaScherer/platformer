#ifndef PLATFORMER_PLATFORM_H
#define PLATFORMER_PLATFORM_H

#include "Object.h"


class Platform : public Object {
public:
    Platform(sf::Vector2<float> position, sf::Vector2<float> size, sf::Color color);
};


#endif //PLATFORMER_PLATFORM_H
