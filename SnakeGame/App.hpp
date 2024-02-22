#pragma once
#include "Window.hpp"

class App {
private:
	Window	  window;
	sf::Clock timer;
	sf::Time  frameTime;
	sf::Time  elapsedTime;

	void createFrame();
	void drawFunc();
	void updateScene();
	void keybordPressed(sf::Keyboard::Key key);
	void keybordReleased(sf::Keyboard::Key key);
	void mouseMove(sf::Event::MouseMoveEvent event);
	void mousePressed(sf::Event::MouseButtonEvent event);
public:
	App();
	void build(unsigned int width, unsigned int height);
	void start(int fps = 60);
};