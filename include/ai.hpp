#pragma once

enum class EnemyState {
  IDLE,
  PATROL,
  CHASE,
  ATTACK,
  DEAD,
  PASSIVE
};

struct AI {
  EnemyState state;
  float detectionRadius;
  bool playerDetected;
};
