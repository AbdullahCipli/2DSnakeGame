#include "Mapp.hpp"
#include "Window.hpp"
Mapp::Mapp() {
	v_line.setFillColor(sf::Color::Blue);
	h_line.setFillColor(sf::Color::Blue);
}
void Mapp::draw(Window& window)
{
	sf::Vector2f location;
	for (int i = 0; i <= n_line; i++) {
		location.x = 0;
		location.y = i * interval;
		h_line.setPosition(location);
		window.draw(h_line);
	}
	for (int i = 0; i <= n_line; i++) {
		location.x = i * interval;
		location.y = 0;
		v_line.setPosition(location);
		window.draw(v_line);
	}
}

void Mapp::settings(int length, int interval)
{
	this->length = length;
	this->interval = interval;
	n_line = (length / interval) ;
	
	v_line.setSize(sf::Vector2f(1,length));
	h_line.setSize(sf::Vector2f(length, 1));
}
