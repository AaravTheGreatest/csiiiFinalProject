#include <string>
#include <vector>

enum class EnemyState {
  IDLE,
  PATROL,
  CHASE,
  ATTACK,
  DEAD,
  PASSIVE
};

struct attack {
  int damage, range, cooldown;
};

struct Enemy {
  EnemyState state;
  std::string name, type;
  float speed, attCooldown, attTimer, animTimer, stunTimer;
  int health, maxHealth, detRadius, anim;
  sf::Vector2f spawnPoint, pos, dir, vel;
  std::vector<attack> attacks;
  bool playerDet, alive, stunned;
  std::vector<sf::Sprite> sprite;
  sf::FloatRect hitbox, hurtbox;
  std::vector<sf::Vector2f> path;
  size_t pathIndex;
};
