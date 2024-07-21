#include "SFML/Graphics.hpp"
#include "Player.h"
#include "constants.h"
#include "Platform.h"
#include <chrono>
#include <vector>
#include <iostream>

Object* createPlatform(float x, float y, float width, float height)
{
  Object* platform = new Platform({x, y}, {width, height}, {200, 64, 180});
  return platform;
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "S-Dawg's window", sf::Style::Titlebar | sf::Style::Close);

  std::vector<Object*> objects;

  Object* square = new Player({0, 0});
  objects.push_back(square);

  Object* platform = createPlatform(50, 500, 150, 50);
  objects.push_back(platform);

  for (auto object : objects)
  {
    object->bindWindow(&window);
  }

  std::chrono::steady_clock::time_point previous = std::chrono::steady_clock::now();
  float dt;
  float timeAccumulator = 0;

  while (window.isOpen()) {
    sf::Event event{};

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
        window.close();
    }

    window.clear(sf::Color::Black);

    while (timeAccumulator > PHYSICS_DT)
    {
      for (auto object : objects)
      {
        object->update();
      }

      timeAccumulator -= PHYSICS_DT;
    }

    for (auto object : objects)
    {
      object->draw();
    }

    auto* player = dynamic_cast<Player*>(square);
    if (player) {
      player->resolveCollisions(square, platform);
    }

    window.display();

    std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
    dt = static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(current - previous).count()) / 1000000.0f;

    timeAccumulator += dt;

    previous = current;
  }

  for (auto object : objects)
  {
    delete object;
  }

  return 0;
}