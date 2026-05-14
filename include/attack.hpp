#pragma once

struct Attack {
  int damage, range;
  float cooldown, timer;
  std::vector<sf::Sprite> animation; // attack animation, optional for if the attack has some big visual, otherwise will be in the user's animations
};
