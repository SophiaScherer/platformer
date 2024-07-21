#ifndef PLATFORMER_OBJECT_H
#define PLATFORMER_OBJECT_H

#include <SFML/Graphics.hpp>

class Object {
public:
    explicit Object(sf::Vector2<float> position);

    [[nodiscard]] float getX() const;
    [[nodiscard]] float getY() const;

    virtual void update();

    void bindWindow(sf::RenderWindow* window);

    void draw();

    static bool colliding(const Object* a, const Object* b);

    static sf::Vector2<float> getMtv(const Object* a, const Object* b);

protected:
  sf::Vector2<float> position;

  float width;
  float height;

  sf::RenderWindow* m_window;

  sf::Color fillColor = sf::Color(100, 250, 50);
};


#endif //PLATFORMER_OBJECT_H
