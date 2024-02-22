#include "Snake.hpp"
#include <iostream>

void Snake::draw(Window& window)
{
	
	for (auto& next : cells) {
		next.draw(window);
	}
}

void Snake::setDirection(CellDirection newDirection)
{
	if(newDirection == CellDirection::Right && cells[0].getDirection() == CellDirection::Left) {
	}
	else if (newDirection == CellDirection::Left && cells[0].getDirection() == CellDirection::Right) {
	}
	else if (newDirection == CellDirection::Up && cells[0].getDirection() == CellDirection::Down) {
	}
	else if (newDirection == CellDirection::Down && cells[0].getDirection() == CellDirection::Up) {
	}
	else {
		captainDirection = newDirection;
	}
}



void Snake::move()
{
	for (auto& next : cells) {
		next.move();
	}
	distance += cells[0].getSpeed();
	if ((int)distance%20 == 0) {
;
		for (int i = cells.size() - 1; i > 0; i--) {
			cells[i].setDirection(cells[i - 1].getDirection());
		}
		cells[0].setDirection(captainDirection);
		distance = 0.0f;
	}

}




void Snake::addTail()
{
	if (cells.size()) {
		Cell newCell = cells.back().createCell();
		cells.push_back(newCell);
	}
	else {
		cells.push_back(Cell(5, CellDirection::Right, sf::Color::Green, sf::Vector2f(0,0)));
	}
}

void Snake::eatFood(Food& food)
{
		if (cells[0].getLocation() == food.getLocation()) {
			createFood(food);
			addTail();
		}

}

void Snake::createFood(Food& food)
{
	food.setLocation();
	for (auto& next : cells) {
		if (next.getLocation() != food.getLocation());
		else createFood(food);
	}
}

sf::Vector2f Snake::mapSettings(float width, float height)
{
	mapSize.x = width;
	mapSize.y = height;
	return mapSize;
}
