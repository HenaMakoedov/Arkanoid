/**
* Arkanoid
* an open source cross-platform free game
* @author Makoedov Hennadii
* @country Ukraine
* @city Kharkiv
* @support Hennadii.Makoedov@gmail.com
*/

#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include "include/ball.h"
#include "include/platform.h"
#include "include/global.h"
#include "include/backGround.h"
#include "include/tile.h"
#include "include/tilemap.h"
#include "include/gameObjects.h"



using namespace sf;


int main()
{
    srand(time(NULL));

    //create and tune the window
    RenderWindow window(sf::VideoMode(600,600), "Arkanoid");
    window.setPosition(Vector2i(300,100));
    window.setFramerateLimit(60);

    //add the game objects
    BackGround* backGround = new BackGround();
    Platform* plt = new Platform();
    TileMap* tileMap = new TileMap();
    Ball* ball = new Ball();
    GameObjects* container = new GameObjects(ball, plt, backGround, tileMap);


    //clock ^_^
    //need to create the speed of the game
    Clock clock;

    //main loop of the game
    //responsible for drawing games and game mechanic
	while (window.isOpen())
	{
	    //create game speed
	    float time = clock.getElapsedTime().asMicroseconds();
	    clock.restart();
	    time /= 250;

        //event in the game mechanic
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();

        //update game objects
        container->update(window, time);


        window.display();

	}

	//free memory
	delete container;
        delete ball;
        delete tileMap;
	delete plt;
	delete backGround;

	return 0;
}
