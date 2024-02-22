#pragma once
#include<SFML/Graphics.hpp>

class Window;
class Drawble{
protected:
	sf::Vector2f location;
public:
	virtual void draw(Window &window) = 0;
	void setLocation(const sf::Vector2f &location);
	sf::Vector2f getLocation();
 };