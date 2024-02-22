#pragma once
#include "Snake.hpp"
#include "SelfSnake.hpp"
class SelfSnake;
class EnemySnake : public Snake {
private:
	float turnTime;
	float time;
	int turn;
	int speed;
	sf::Color color;
	sf::Vector2f position;
	bool perTurn;
public:
	EnemySnake(int newSpeed, sf::Color newColor, sf::Vector2f newPosition);
	void addTail();
	void move();
	void inBorder();
	void moves();
	sf::Vector2f cellsLocation(int cellnum);
	void eatSnake(SelfSnake& a);
	int getCellSize();
};

