#include "SelfSnake.hpp"

SelfSnake::SelfSnake()
{
	addTail();
	addTail();
	distance = 0.0f;
	captainDirection = CellDirection::Right;
}
void SelfSnake::eatSelf()
{
	for (int i = 1; i < cells.size(); i++) {
		if (cells[0].getLocation() == cells[i].getLocation())
		{
			for (auto& next : cells) next.setSpeed(0);
		}
	}
}

void SelfSnake::inBorder()
{

	if (cells[0].getLocation().x == -5 ||
		cells[0].getLocation().x == mapSize.x + 25 ||
		cells[0].getLocation().y == -5 ||
		cells[0].getLocation().y == mapSize.x + 25) {
		for (auto& next : cells) {
			next.setSpeed(0);
		}
	}

}

void SelfSnake::eatEnemy(EnemySnake& a)
{
	for (int i = 0; i < a.getCellSize(); i++) {
		if (cells[0].getLocation() == a.cellsLocation(i)) {
			for (auto& next : cells) {
				next.setSpeed(0);
			}
		}

	}
		
}

sf::Vector2f SelfSnake::cellsLocation(int cellnum)
{
	return cells[cellnum].getLocation();
}

int SelfSnake::getCellSize()
{
	return cells.size();
}



