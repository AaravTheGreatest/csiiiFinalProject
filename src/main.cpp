#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <helpers.hpp>
#include <entity.hpp>
#include <assets.hpp>
#include <render.hpp>

int main() {
  float x = 10.0f, y = 10.0f, speed = 200.0f, normSpeed = 200.0f, sprintSpeed = 300.0f, ADMIN_TOTAL_SPEED_RAHHHHHHHH = 20000.0f;
  bool left = false;
  sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
  playerSprite.setScale(sf::Vector2f(5.f, 5.f));
  const sf::Font font("./assets/Minecraft.ttf");
  int ground[121][127];
  GameWindow win{ground, window.getSize().x, window.getSize().y, window};
  for (int i = 0; i < 121; i++) {
    for (int j = 0; j < 127; j++) {
      win.ground[i][j] = GRASS;
    }
  }
  for (int i = 5; i < 8; i++) {
    for (int j = 0; j < 21; j++) {
      win.ground[i][j] = PATH;
    }
  }
  sf::View game({0.f, 0.f}, {800.f, 600.f});
  initEntities();
  while (window.isOpen()) {
    window.clear();
    handleEvents(win.win, win.windowX, win.windowY);
    move(win.win, entities, game);
    render(win, entities);
    window.display();
  }
}
