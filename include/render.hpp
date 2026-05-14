#pragma once

enum groundType {
  GRASS, PATH, ROCK1, ROCK2, ROCK3, ROCK4, ROCK5
};

struct GameWindow {
  int (&ground)[121][127];
  unsigned int windowX, windowY;
  sf::RenderWindow &win;
};

void render(GameWindow window);
