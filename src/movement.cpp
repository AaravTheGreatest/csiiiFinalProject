#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include <cmath>
#include <entity.hpp>

float speed = 200.0f, normSpeed = 200.0f, sprintSpeed = 300.0f, ADMIN_TOTAL_SPEED_RAHHHHHHHH = 20000.0f;
sf::Clock gameClock;
bool left = false;
void move(sf::RenderWindow& win, std::vector<Entity>& entities, sf::View& game) {
  for (Entity& e: entities) {
    if (e.type == EntityType::PLAYER) {
      // Keyboard movement logic
      e.movement.dir = sf::Vector2f(0.0f, 0.0f);
      float dt = gameClock.restart().asSeconds();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) speed = sprintSpeed;
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift)) speed = ADMIN_TOTAL_SPEED_RAHHHHHHHH;
      else speed = normSpeed;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) e.movement.dir.y -= 1;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) e.movement.dir.y += 1;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) { e.movement.dir.x += 1; left = false; }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) { e.movement.dir.x -= 1; left = true; }
      if (left) { e.animation.sprite.setScale(sf::Vector2f(-1.0f, 1.0f)); e.animation.sprite.setOrigin(sf::Vector2f(120.0f, 0.0f)); }
      else { e.animation.sprite.setScale(sf::Vector2f(1.0f, 1.0f)); e.animation.sprite.setOrigin(sf::Vector2f(0.0f, 0.0f)); }
      float len = std::sqrt(e.movement.dir.x * e.movement.dir.x + e.movement.dir.y * e.movement.dir.y);
      if (len > 0) e.movement.dir /= len;
      e.animation.sprite.move(sf::Vector2f(e.movement.dir.x * speed * dt, e.movement.dir.y * speed * dt));
      e.movement.pos = e.animation.sprite.getPosition();
      if (e.animation.sprite.getPosition().x <= -30) e.animation.sprite.setPosition({-30.0f, e.animation.sprite.getPosition().y});
      if (e.animation.sprite.getPosition().y <= 0) e.animation.sprite.setPosition({e.animation.sprite.getPosition().x, 0.0f});
      game.setCenter(e.movement.pos);
      win.setView(game);
    }
    else if (e.type == EntityType::ENEMY) {
      // AI movement logic
    }
    else if (e.type == EntityType::PASSIVE) {
      // Passive AI movement logic
    }
  }
}
