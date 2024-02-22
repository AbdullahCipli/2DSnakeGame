#pragma once
#include "Draw.hpp"
#include "Cell.hpp"
#include "Food.hpp"
class Snake : public Drawble {
protected: 
	std::vector <Cell> cells;
	float              distance;
	CellDirection	   captainDirection;
	CellDirection	   direction;
	sf::Vector2f       mapSize;
public:
	void draw(Window& window)override;
	void setDirection(CellDirection newDirection);
	void move();
	void addTail();
	void eatFood(Food &food);
	void createFood(Food &food);
	sf::Vector2f mapSettings(float width, float height);
};
	