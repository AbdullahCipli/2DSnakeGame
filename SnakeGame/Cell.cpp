#include "Cell.hpp"
#include "Window.hpp"
Cell::Cell(sf::Color newColor)
{
	setColor(newColor);
	shape.setFillColor(getColor());
	shape.setOutlineColor(sf::Color::Blue);
	shape.setOutlineThickness(0.75);
	setSize(20);
	setDirection(CellDirection::Right);
}
Cell::Cell(int newSpeed, CellDirection newDirection, sf::Color newColor, sf::Vector2f newLocation):Cell(newColor)
{
	setSpeed(newSpeed);
	setLocation(newLocation);
	shape.setPosition(getLocation());
	setDirection(newDirection);
}
void Cell::draw(Window& window)
{
	shape.setPosition(location);
	window.draw(shape);
}

Cell Cell::createCell()
{
	sf::Vector2f newLocation = location;
	switch (direction) {
	case CellDirection::Up:
		newLocation.y += size;
		break;
	case CellDirection::Down:	
		newLocation.y -= size;
		break;
	case CellDirection::Right:
		newLocation.x -= size;
		break;
	case CellDirection::Left:
		newLocation.x += size;
		break;
	}
	Cell newCell(getColor());
	newCell.setSpeed(getSpeed());
	newCell.setLocation(newLocation);
	newCell.setDirection(direction);
	return newCell;
}

void Cell::setDirection(CellDirection g_direction)
{
	direction = g_direction;
}

CellDirection Cell::getDirection()
{
	return direction;
}

void Cell::setSize(float size)
{
	this->size = size;
	shape.setSize(sf::Vector2f(this->size, this->size));
}

float Cell::getSize()
{
	return size;
}

void Cell::setSpeed(float speed)
{
	this->speed = speed;
}

float Cell::getSpeed()
{
	return speed;
}

void Cell::move()
{
	switch (direction) {
	case CellDirection::Up:
		location.y -= speed;
		break;
	case CellDirection::Down:
		location.y += speed;
		break;
	case CellDirection::Right:
		location.x += speed;
		break;
	case CellDirection::Left:
		location.x -= speed;
		break;
	}
}

void Cell::setColor(sf::Color newColor)
{
	color = newColor;
}

sf::Color Cell::getColor()
{
	return color;
}