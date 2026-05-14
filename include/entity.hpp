#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include "attack.hpp"
#include "ai.hpp"
#include "movement.hpp"
#include "health.hpp"
#include "animation.hpp"

enum class EntityType {
  MONSTER,
  PLAYER,
  PASSIVE
};

struct Entity {
  std::optional<AI> ai;
  Movement movement;
  Health health;
  Animation animation;
  std::string name;
  EntityType type;
  std::vector<Attack> attacks;
  sf::FloatRect hitbox, hurtbox;
};

void initEntities();
