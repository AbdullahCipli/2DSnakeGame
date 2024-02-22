#pragma once
#include "Draw.hpp"


class Window;
class Food : public Drawble{
private:
	sf::RectangleShape foodShape;
; public:
				 Food(); 
	void		 draw(Window& window);
	void		 setLocation();
};