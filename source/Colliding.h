#ifndef PLATFORMER_COLLIDING_H
#define PLATFORMER_COLLIDING_H

#include "Square.h"
#include "Platform.h"

class Colliding {
public:
  static bool colliding(Object* a, Object* b);
};


#endif //PLATFORMER_COLLIDING_H
