#pragma once

struct Animation {
  float animTimer;
  int frame;
  sf::Texture texture;
  sf::Sprite sprite; // I'll use different 32x32 chunks of a bigger image for animation frames instead of multiple sprites
};

