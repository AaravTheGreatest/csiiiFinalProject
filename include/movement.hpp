#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>

struct Movement {
  sf::Vector2f spawnPoint, pos, dir, vel;
  float speed;
  std::vector<sf::Vector2f> path;
  size_t pathIndex;
};
