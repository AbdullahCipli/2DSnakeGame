#include "App.hpp"
#include "Cell.hpp"
#include "Mapp.hpp"
#include "SelfSnake.hpp"
#include "EnemySnake.hpp"
#include "Food.hpp"
Mapp mapp;
SelfSnake snake;
EnemySnake enemysnake(5,sf::Color::Red , sf::Vector2f(500,500));
EnemySnake enemysnake1(5, sf::Color::Cyan, sf::Vector2f(200,200));
EnemySnake enemysnake2(5, sf::Color::Magenta, sf::Vector2f(300, 300));
EnemySnake enemysnake3(5, sf::Color::Yellow, sf::Vector2f(20, 540));
Food food;
Food food1;
Food food2;
void App::createFrame()
{
	updateScene();
	drawFunc();
}

void App::drawFunc()
{
	window.wClear();
	mapp.draw(window);
	snake.draw(window);
	enemysnake.draw(window);
	enemysnake1.draw(window);
	enemysnake2.draw(window);
	enemysnake3.draw(window);
	food.draw(window);
	food1.draw(window);
	food2.draw(window);
	window.wDisplay();
}

void App::updateScene()
{
	snake.move();
	enemysnake.move();
	enemysnake1.move();
	enemysnake2.move();
	enemysnake3.move();
 	snake.eatEnemy(enemysnake);
	snake.eatEnemy(enemysnake1);
	snake.eatEnemy(enemysnake2);
	snake.eatEnemy(enemysnake3);
	enemysnake.eatSnake(snake);
	enemysnake1.eatSnake(snake);
	enemysnake2.eatSnake(snake);
	enemysnake3.eatSnake(snake);
	snake.eatFood(food);
	enemysnake.eatFood(food);
	enemysnake1.eatFood(food);
	enemysnake2.eatFood(food);
	enemysnake3.eatFood(food);
	snake.eatFood(food1);
	enemysnake.eatFood(food1);
	enemysnake1.eatFood(food1);
	enemysnake2.eatFood(food1);
	enemysnake3.eatFood(food1);
	snake.eatFood(food2);
	enemysnake.eatFood(food2);
	enemysnake1.eatFood(food2);
	enemysnake2.eatFood(food2);
	enemysnake3.eatFood(food2);
	snake.eatSelf();
	snake.inBorder();
}

void App::keybordPressed(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Left)
	{
		snake.setDirection(CellDirection::Left);
	}
	if (key == sf::Keyboard::Right)
	{
		snake.setDirection(CellDirection::Right);;

	}
	if (key == sf::Keyboard::Down)
	{
		snake.setDirection(CellDirection::Down);
	}
	if (key == sf::Keyboard::Up)
	{
		snake.setDirection(CellDirection::Up);

	}
	if (key == sf::Keyboard::Space) {
		snake.addTail();
	}

}

void App::keybordReleased(sf::Keyboard::Key key)
{
}

void App::mouseMove(sf::Event::MouseMoveEvent event)
{
}

void App::mousePressed(sf::Event::MouseButtonEvent event)
{
}



App::App()
{
}

void App::build(unsigned int width, unsigned int height)
{
	window.setWindow(width, height);
	mapp.settings(600 , 20);
	snake.mapSettings(width, height);
	enemysnake.mapSettings(width, height);
	enemysnake1.mapSettings(width, height);
	enemysnake2.mapSettings(width, height);
	enemysnake3.mapSettings(width, height);
	window.addMouseMoveFunc(std::bind(&App::mouseMove, this, std::placeholders::_1));
	window.addMouseButtonFunc(std::bind(&App::mousePressed, this, std::placeholders::_1));
	window.addKeyPressFunc(std::bind(&App::keybordPressed, this, std::placeholders::_1));
	window.addKeyReleaseFunc(std::bind(&App::keybordReleased, this, std::placeholders::_1));
}

void App::start(int fps)
{
	float frameFps = 1.0f / fps;
	frameTime = sf::seconds(frameFps);

	elapsedTime = timer.restart();
	while (window.windowIsOpen())
	{
		window.processEvents();

		elapsedTime = timer.getElapsedTime();
		if (elapsedTime >= frameTime)
		{
			createFrame();
			timer.restart();
		}
		else
		{
			sf::sleep(frameTime - elapsedTime);

		}
	}
}

