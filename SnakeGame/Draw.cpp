#include "Draw.hpp"

void Drawble::draw(Window& window)
{
}

void Drawble::setLocation(const sf::Vector2f& location)
{
	this->location = location;
}

sf::Vector2f Drawble::getLocation()
{
	return location;
}
