#include <SFML/Graphics/RenderWindow.hpp>
#include <entity.hpp>
#include <assets.hpp>
#include <render.hpp>
#include <vector>
#include <iostream>
#include <exception>

void render(GameWindow window, std::vector<Entity> entities) {
  // Ground
  for (int i = 0; i < 121; i++) {
    for (int j = 0; j < 127; j++) {
      sprite.setTexture(grassTexture);
      sprite.setPosition(sf::Vector2f(j * 32, i * 32));
      window.win.draw(sprite);
    }
  }
  // Entities
  for (Entity e : entities) {
    e.animation.sprite.setPosition(e.movement.pos);
    window.win.draw(e.animation.sprite);
  }
  // HUD
  sf::Text HUDText(font, "x: " + std::to_string(entities[1].movement.pos.x) + ", y: " + std::to_string(entities[1].movement.pos.y) + ", speed: " + std::to_string(entities[1].movement.speed), 10);
  HUDText.setPosition(sf::Vector2f(500.f, 0.f));
  window.win.draw(HUDText);
}

