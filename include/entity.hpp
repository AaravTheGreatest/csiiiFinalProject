#pragma once
#include <string>
#include <vector>
#include "attack.hpp"
#include "ai.hpp"
#include "movement.hpp"
#include "health.hpp"
#include "animation.hpp"

struct Enemy {
  AI ai;
  MovementSys movement;
  Health health;
  Animation animation;
  std::string name, type;
  std::vector<Attack> attacks;
  sf::FloatRect hitbox, hurtbox;
};
