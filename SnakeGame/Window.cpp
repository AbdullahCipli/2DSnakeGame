#include "window.hpp"
using namespace std;
void Window::setWindow(unsigned int width, unsigned int hight, const sf::String& title)
{
	window.create(sf::VideoMode(width, hight), title );

}

void Window::draw(sf::Drawable& shape)
{
	window.draw(shape);
}

void Window::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			for (KeybordFunc next : wKeyPressedFunc)
			{

				next(event.key.code);

			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			for (KeybordFunc next : wKeyReleasedFunc)
			{
				next(event.key.code);
			}
		}
		if (event.type == sf::Event::MouseMoved)
		{
			for (MouseFunc next : wMouseMovedFunc)
			{
				next(event.mouseMove);

			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			for (MouseButtonFunc next : wMousePressedFunc)
			{
				next(event.mouseButton);
			}
		}
	}
}

bool Window::windowIsOpen()
{
	return window.isOpen();
}

void Window::wClear()
{
	window.clear(sf::Color::White);
}

void Window::wDisplay()
{
	window.display();
}

void Window::addKeyPressFunc(KeybordFunc newFunc)
{
	wKeyPressedFunc.push_back(newFunc);
}

void Window::addKeyReleaseFunc(KeybordFunc newFunc)
{
	wKeyReleasedFunc.push_back(newFunc);
}

void Window::addMouseMoveFunc(MouseFunc newFunc)
{
	wMouseMovedFunc.push_back(newFunc);
}

void Window::addMouseButtonFunc(MouseButtonFunc newFunc)
{
	wMousePressedFunc.push_back(newFunc);
}


