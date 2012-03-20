//============================================================================
// Name        : Portal-Wombat.cpp
// Author      : zodiac
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2d.h>
#include <iostream>
#include <ctime>

int main()
{
	//Create the Window of the Application
	sf::RenderWindow window(sf::VideoMode(1600,600,32), "Project Portal Wombat");
	sf::Color peru(205,133,63);
	sf::Color forestGreen(34,139,34);

	sf::ConvexShape terrain;
		terrain.setPointCount(6);
		terrain.setPoint(0, sf::Vector2f(0,500));
		terrain.setPoint(1, sf::Vector2f(800,500));
		terrain.setPoint(2, sf::Vector2f(1400,400));
		terrain.setPoint(3, sf::Vector2f(1900,500));
		terrain.setPoint(4, sf::Vector2f(1900,600));
		terrain.setPoint(5, sf::Vector2f(0,600));
		terrain.setOutlineColor(forestGreen);
		terrain.setFillColor(peru);
		terrain.setOutlineThickness(10);
		terrain.setPosition(0, 80);

	sf::ConvexShape box;
		box.setPointCount(4);
		box.setPoint(0, sf::Vector2f(0,0));
		box.setPoint(1, sf::Vector2f(50,0));
		box.setPoint(2, sf::Vector2f(50,50));
		box.setPoint(3, sf::Vector2f(0,50));
		box.setFillColor(sf::Color::Red);
		box.setPosition(200,200);

	//Gameloop
	while(window.isOpen())
	{
		sf::Event event;
		sf::Clock clock;
		float deltaTime = clock.restart().asSeconds();

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		//Controls of the Box
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && box.getPosition().y > 0)
		{
			box.move(0.f, -40000.f * deltaTime);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && box.getPosition().y + 50 < 600)
		{
			box.move(0.f, 40000.f * deltaTime);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && box.getPosition().x > 0)
		{
			box.move(-40000.f * deltaTime, 0.f);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && box.getPosition().x + 50 < 1600)
		{
			box.move(40000.f * deltaTime, 0.f);
		}


		window.clear();
		window.draw(terrain);
		window.draw(box);
		window.display();
	}

	return EXIT_SUCCESS;
}
