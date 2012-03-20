//============================================================================
// Name        : main.cpp
// Author      : Simon Kunze
// Version     : 0.1
// Copyright   : Simon Kunze
// Description : main of portal-wombat
//============================================================================

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//Creation of dynamic Field to store all available Modes in
	vector<sf::VideoMode> aModes = sf::VideoMode::getFullscreenModes();
	//Getting available Modes (Resolution and Depth) for Fullscreen
	for (size_t i = 0; i < aModes.size(); ++i)
	{
		sf::VideoMode aMode = aModes[i];
		cout << "Mode No " << i
					<< "( " << aMode.width << " x " << aMode.height
						<< " - " << aMode.bitsPerPixel << " bpp" << endl;
	}
	//Creation of Main Window, Resolution selectable by Mode-Selection
	sf::RenderWindow window(aModes[11], "Portal Wombat");
	//Gravity Vector for Box2D World
	b2Vec2 gravity(0.f, -10.f);
	bool doSleep = true;
	//Creation of physical affected World (Box2D)
	b2World world(gravity, doSleep);

	//Gameloop
	while(window.isOpen())
	{
		//Process Events
		sf::Event event;
		while(window.pollEvent(event))
		{
			//Close Window on Exit
			if(event.type == sf::Event::Closed)
				window.close();
		}

	//Clear former Stuff from Screen
		window.clear(sf::Color::White);

	//Display ALL the Shit!
		window.display();
	}

	return EXIT_SUCCESS;
}
