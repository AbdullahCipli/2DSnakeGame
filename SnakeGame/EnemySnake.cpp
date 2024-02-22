#include "EnemySnake.hpp"
#include <iostream>
using namespace std;


EnemySnake::EnemySnake(int newSpeed , sf::Color newColor, sf::Vector2f newPosition)
{
	speed = newSpeed;
	position = newPosition;
	color = newColor;
	addTail();
	addTail();
	addTail();
	addTail(); addTail();
	addTail();
	distance = 0.0f;
	captainDirection = CellDirection::Right;
	turnTime = ((rand() % 7) + 1) * 2;
	time = 0.0f;
	cout << turnTime << endl;
}


void EnemySnake::addTail()
{
	if (cells.size()) {
		Cell newCell = cells.back().createCell();
		cells.push_back(newCell);
	}
	else {
		cells.push_back(Cell(speed, CellDirection::Down, color, position));
	}
}

void EnemySnake::move()
{
	for (auto& next : cells) {
		next.move();
	}
	inBorder();
	time += 0.2f;
	if ((int)time == (float)turnTime) {
		if ((cells[0].getLocation() == sf::Vector2f(-20, cells[0].getLocation().y)) || 
			(cells[0].getLocation() == sf::Vector2f(mapSize.x, cells[0].getLocation().y)) ||
			(cells[0].getLocation() == sf::Vector2f(cells[0].getLocation().x, -20))||
			(cells[0].getLocation() == sf::Vector2f(cells[0].getLocation().x, -mapSize.y)))
		{
			time = 0.0f;
			turnTime = ((rand() % 7) + 1) * 2;
		}
		else {
			moves();
			time = 0.0f;
			turnTime = ((rand() % 7) + 1) * 2;
		}
	}
	distance += cells[0].getSpeed();
	if ((int)distance % 20 == 0) {
		for (int i = cells.size() - 1; i > 0; i--) {
			cells[i].setDirection(cells[i - 1].getDirection());
		}
		cells[0].setDirection(captainDirection);
		distance = 0.0f;
	}
}

void EnemySnake::inBorder()
{
	for (auto& next : cells) {
		if (next.getLocation().x == mapSize.x) {
			next.setLocation(sf::Vector2f(0, next.getLocation().y));
		}
		else if (next.getLocation().x == - 20) {
			next.setLocation(sf::Vector2f(mapSize.x - 20, next.getLocation().y));
		}
		else if (next.getLocation().y == -20) {
			next.setLocation(sf::Vector2f(next.getLocation().x, mapSize.y - 20));
		}
		else if (next.getLocation().y == mapSize.y) {
			next.setLocation(sf::Vector2f(next.getLocation().x, 0));
		}
	}
}

void EnemySnake::moves()
{
	turn = (rand() % 2);
	switch (captainDirection)
	{
	case CellDirection::Right:
		if(turn == 0) captainDirection = CellDirection::Up;
		else captainDirection = CellDirection::Down;
		break;
	case CellDirection::Down:
		if (turn == 0) captainDirection = CellDirection::Right;
		else captainDirection = CellDirection::Left;
		break;
	case CellDirection::Up:
		if (turn == 0) captainDirection = CellDirection::Right;
		else captainDirection = CellDirection::Left;
		break;
	case CellDirection::Left:
		if (turn == 0) captainDirection = CellDirection::Up;
		else captainDirection = CellDirection::Down;
		break;
	}
}

sf::Vector2f EnemySnake::cellsLocation(int cellnum)
{
	return cells[cellnum].getLocation();
}

void EnemySnake::eatSnake(SelfSnake& a)
{
	for (int i = 0; i < a.getCellSize(); i++) {
		if (cells[0].getLocation() == a.cellsLocation(i)) {
			for (auto& next : cells) {
				next.setSpeed(0);

			}
		}

	}
}

	int EnemySnake::getCellSize() {
		return cells.size();
	}