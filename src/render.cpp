#include <SFML/Graphics/RenderWindow.hpp>
#include <entity.hpp>
#include <assets.hpp>
#include <render.hpp>

void render(GameWindow window) {
  // Ground
  for (int i = 0; i < 121; i++) {
    for (int j = 0; j < 127; j++) {
      switch(window.ground[i][j]) {
          case (groundType::GRASS):
            grassSprite.setPosition(sf::Vector2f(j * 32, i * 32));
            window.win.draw(grassSprite);
            break;
          case (groundType::PATH):
            pathSprite.setPosition(sf::Vector2f(j * 32, i * 32));
            window.win.draw(pathSprite);
            break;
          case (groundType::ROCK1):
            rock1Sprite.setPosition(sf::Vector2f(j * 32, i * 32));
            window.win.draw(rock1Sprite);
            break;
          case (groundType::ROCK2):
            rock2Sprite.setPosition(sf::Vector2f(j * 32, i * 32));
            window.win.draw(rock2Sprite);
            break;
          case (groundType::ROCK3):
            rock3Sprite.setPosition(sf::Vector2f(j * 32, i * 32));
            window.win.draw(rock3Sprite);
            break;
          case (groundType::ROCK4):
            rock4Sprite.setPosition(sf::Vector2f(j * 32, i * 32));
            window.win.draw(rock4Sprite);
            break;
          case (groundType::ROCK5):
            rock5Sprite.setPosition(sf::Vector2f(j * 32, i * 32));
            window.win.draw(rock5Sprite);
            break;

      }
    }
  }
  // Entities

  // HUD

}

