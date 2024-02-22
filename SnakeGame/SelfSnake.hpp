#pragma once

#include "Snake.hpp"
#include "EnemySnake.hpp"
class EnemySnake;
class SelfSnake : public Snake {
public:
	SelfSnake();
	void eatSelf();
	void inBorder();
	void eatEnemy(EnemySnake &a);
	sf::Vector2f cellsLocation(int cellnum);
	int getCellSize();
};