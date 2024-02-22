#pragma once

#include "Draw.hpp"
enum class CellDirection 
{
	Left,
	Right,
	Up,
	Down

};

class Cell : public Drawble  
{		
protected:
	CellDirection       direction;
	float				speed;
	sf::RectangleShape	shape;
	float				size;
	sf::Color		    color;
public:
	Cell(sf::Color newColor);
	Cell(int newSpeed, CellDirection newDirection, sf::Color newColor, sf::Vector2f newLocation);
	void draw(Window& window) override;
	Cell          createCell();
	void		  setDirection(CellDirection g_direction);
	CellDirection getDirection();
	void		  setSize(float size);
	float	      getSize();
	void		  setSpeed(float speed);
	float		  getSpeed();
	void		  move();
	void		  setColor(sf::Color newColor);
	sf::Color     getColor();
};