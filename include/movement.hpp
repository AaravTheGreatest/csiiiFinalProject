#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

struct Entity;

struct Movement {
  sf::Vector2f spawnPoint, pos, dir, vel;
  float speed;
  std::optional<std::vector<sf::Vector2f>> path;
  std::optional<size_t> pathIndex;
};
void move(sf::RenderWindow& win, std::vector<Entity>& entities, sf::View& game);
