#pragma once
#include<functional>
#include<vector>
#include<SFML/Window/Event.hpp>

typedef std::function < void(sf::Keyboard::Key) > KeybordFunc;
typedef std::vector < KeybordFunc > KeybordFuncList;

typedef std::function < void(sf::Event::MouseMoveEvent) > MouseFunc;
typedef std::vector < MouseFunc > MouseFuncList;

typedef std::function < void(sf::Event::MouseButtonEvent) > MouseButtonFunc;
typedef std::vector < MouseButtonFunc > MouseButtonFuncList;