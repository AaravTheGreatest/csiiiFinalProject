#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <helpers.hpp>
#include <entity.hpp>

enum ground {
  GRASS, PATH, ROCK
};

int main() {
  float x = 10.0f, y = 10.0f, speed = 200.0f, normSpeed = 200.0f, sprintSpeed = 300.0f, ADMIN_TOTAL_SPEED_RAHHHHHHHH = 20000.0f;
  bool left = false;
  sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
  const sf::Texture texture("./assets/character.png"), grassTexture("./assets/grass.png"), pathTexture("./assets/path.png");
  sf::Sprite sprite(texture);
  sf::Sprite grass(grassTexture);
  sf::Sprite path(pathTexture);
  sprite.setScale(sf::Vector2f(5.f, 5.f));
  const sf::Font font("./assets/Minecraft.ttf");
  sf::Text text(font, "CSIII EOY Project - Aarav Yadav", 25);
  sf::Text HUDText(font, " ", 10);
  HUDText.setPosition(sf::Vector2f(500.f, 0.f));
  std::cout << HUDText.getLocalBounds().size.x << '\n';
  sf::Clock clock;
  Window win{ window, window.getSize().x, window.getSize().y };
  int ground[121][127];
  for (int i = 0; i < 121; i++) {
    for (int j = 0; j < 127; j++) {
      ground[i][j] = GRASS;
    }
  }
  for (int i = 5; i < 8; i++) {
    for (int j = 0; j < 21; j++) {
      ground[i][j] = PATH;
    }
  }
  sf::View game({0.f, 0.f}, {800.f, 600.f});
  initEntities();
  while (window.isOpen()) {
    game.setCenter({x, y});
    window.setView(game);
    sf::Vector2f dir(0.0f, 0.0f);
    handleEvents(win.win, win.windowX, win.windowY);
    float dt = clock.restart().asSeconds(); // all of physics relies on this
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) speed = sprintSpeed;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift)) speed = ADMIN_TOTAL_SPEED_RAHHHHHHHH;
    else speed = normSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) dir.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) dir.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) { dir.x += 1; left = false; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) { dir.x -= 1; left = true; }
    if (left) { sprite.setScale(sf::Vector2f(-5.0f, 5.0f)); sprite.setOrigin(sf::Vector2f(32.0f, 0.0f)); }
    else { sprite.setScale(sf::Vector2f(5.0f, 5.0f)); sprite.setOrigin(sf::Vector2f(0.0f, 0.0f)); }
    float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (len > 0) dir /= len;
    x += dir.x * speed * dt; y += dir.y * speed * dt;
    if (x <= 0) x = 0.0f;
    if (y <= 0) y = 0.0f;
    HUDText.setString("x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", speed: " + std::to_string(speed));
    window.clear();
    sprite.setPosition(sf::Vector2f(x, y));
    for (int i = 0; i < 121; i++) {
      for (int j = 0; j < 127; j++) {
        switch (ground[i][j]) {
          case GRASS:
            grass.setPosition(sf::Vector2f(j * 32, i * 32));
            window.draw(grass);
            break;
          case PATH:
            path.setPosition(sf::Vector2f(j * 32, i * 32));
            window.draw(path);
            break;
          case ROCK:
            break;
        }
      }
    }
    window.draw(grass);
    window.draw(sprite);
    window.draw(HUDText);
    window.draw(text);
    window.display();
  }
}
