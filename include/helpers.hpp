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
void handleEvents(sf::RenderWindow& window, unsigned int& windowX, unsigned int& windowY);
