#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <entity.hpp>

void move(sf::RenderWindow win, std::vector<Entity> entities) {
  for (Entity e: entities) {
    if (e.EntityType == PLAYER) {
      // Keyboard movement logic
      float dt = clock.restart().asSeconds();
      bool left = false;
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
      if (left) { playerSprite.setScale(sf::Vector2f(-5.0f, 5.0f)); playerSprite.setOrigin(sf::Vector2f(32.0f, 0.0f)); }
      else { playerSprite.setScale(sf::Vector2f(5.0f, 5.0f)); playerSprite.setOrigin(sf::Vector2f(0.0f, 0.0f)); }
      float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
      if (len > 0) dir /= len;
      x += dir.x * speed * dt; y += dir.y * speed * dt;
      if (x <= 0) x = 0.0f;
      if (y <= 0) y = 0.0f;
    }
    else if (e.EntityType == ENEMY) {
      // AI movement logic
    }
    else if (e.EntityType == PASSIVE) {
      // Passive AI movement logic
    }
  }
}
