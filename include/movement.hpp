#pragma once

struct MovementSys {
  sf::Vector2f spawnPoint, pos, dir, vel;
  float speed;
  std::vector<sf::Vector2f> path;
  size_t pathIndex;
};
