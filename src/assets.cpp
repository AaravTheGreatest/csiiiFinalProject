#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

sf::Texture defaultTexture("assets/default.png");
sf::Texture playerTexture("assets/character2.png");
sf::Texture straightTrailTexture("assets/floor1_straightTrail.png");
sf::Texture grassTexture("assets/grass.png"); 
sf::Texture pathTexture("assets/path.png");
sf::Texture rock1Texture("assets/rock01.png");
sf::Texture rock2Texture("assets/rock02.png");
sf::Texture rock3Texture("assets/rock03.png");
sf::Texture rock4Texture("assets/rock04.png");
sf::Texture rock5Texture("assets/rock05.png");

sf::Sprite defaultSprite(defaultTexture);
sf::Sprite playerSprite(playerTexture);
sf::Sprite sprite(defaultTexture);

sf::Font font("./assets/Minecraft.ttf");
sf::Text HUDText(font, "", 10);
