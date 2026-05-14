#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

struct Window {
  sf::RenderWindow& win;
  unsigned int windowX, windowY;
};
void handleEvents(sf::RenderWindow& window, unsigned int& windowX, unsigned int& windowY) {
  while (const std::optional event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) window.close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) window.close();
    if (const auto* resized = event->getIf<sf::Event::Resized>()) {
      windowX = resized->size.x; windowY = resized->size.y;
      float gameAspect = 800.f / 600.f; // your original resolution
      float windowAspect = (float)windowX / windowY;
      sf::FloatRect viewport;
      if (windowAspect > gameAspect) {
        float w = gameAspect / windowAspect;
        viewport = sf::FloatRect(sf::Vector2f((1.f - w) / 2.f, 0.f), sf::Vector2f(w, 1.f));
      } 
      else {
        float h = windowAspect / gameAspect;
        viewport = sf::FloatRect(sf::Vector2f(0.f, (1.f - h) / 2.f), sf::Vector2f(1.f, h));
      }
      sf::View view(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(800.f, 600.f)));
      view.setViewport(viewport);
      window.setView(view);
    }   
  }
}
