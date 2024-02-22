#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include "FunctionTypes.hpp"
using namespace std;

class Window {
private:
	sf::RenderWindow	window;

	KeybordFuncList		wKeyPressedFunc;
	KeybordFuncList		wKeyReleasedFunc;

	MouseFuncList		wMouseMovedFunc;
	MouseButtonFuncList wMousePressedFunc;
public:
	void setWindow(	unsigned int width,
					unsigned int hight,
					const sf::String& title = "SFML");
	void draw(sf::Drawable& shape);
	void processEvents();
	bool windowIsOpen();
	void wClear();
	void wDisplay();
	void addKeyPressFunc(KeybordFunc newFunc);
	void addKeyReleaseFunc(KeybordFunc newFunc);
	void addMouseMoveFunc(MouseFunc newFunc);
	void addMouseButtonFunc(MouseButtonFunc newFunc);
};