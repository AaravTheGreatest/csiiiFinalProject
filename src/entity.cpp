#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <entity.hpp>
#include <assets.hpp>
#include <vector>
#include <unordered_map>

#define EntityID = uint32_t

std::vector<Entity> entities;
std::vector<sf::Vector2f> path;
void initEntities() {
  std::vector<Attack> defaultAttacks = {
    Attack{10, 2, 5, 1, {defaultSprite}}
  };
  sf::FloatRect defaultRect({50, 50}, {32, 32});
  entities.push_back(Entity{AI{EnemyState::IDLE, 5, false}, Movement{sf::Vector2f(50, 50), sf::Vector2f(50, 50), sf::Vector2f(0, 0), sf::Vector2f(0, 0), 150.0f, path, 1}, Health{100, 100, true, false, 1}, Animation{0.0f, 0, defaultTexture, defaultSprite}, "Monster", EntityType::MONSTER,  defaultAttacks, defaultRect, defaultRect});
  entities.push_back(Entity{std::nullopt, Movement{{10, 10}, {10, 10}, {0, 0}, {0, 0}, 200.0f}, Health{100, 100, true, false, 1}, Animation{0.0f, 0, playerTexture, playerSprite}, "Player", EntityType::PLAYER, defaultAttacks, defaultRect, defaultRect});
}
