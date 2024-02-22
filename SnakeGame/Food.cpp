#include "Food.hpp"
#include "Window.hpp"
#include <iostream>
Food::Food()
{
	foodShape.setFillColor(sf::Color::Black);
	foodShape.setSize(sf::Vector2f(20, 20));
	setLocation();
	foodShape.setPosition(getLocation());
}
void Food::draw(Window& window)
{
	foodShape.setPosition(location);
	window.draw(foodShape);

}
void Food::setLocation()
{
	location.x = (rand() % 20 )*20 ;
	location.y = (rand() % 20) * 20;
}
