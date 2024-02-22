#pragma once
#include "Draw.hpp"
class Mapp : public Drawble{
private:
	sf::RectangleShape h_line;
	sf::RectangleShape v_line;

	float length;
	float interval;
	int	  n_line;
public:
	Mapp();
	void draw(Window &window)override;
	void settings(int length, int interval);
};