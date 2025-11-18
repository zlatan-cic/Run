#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "GameObject.h"
#include "Factory.h"
#include "InputDispatcher.h"

using namespace std;
using namespace sf;

int main()
{
	// Create Fullscreen window
	RenderWindow window(VideoMode::getDesktopMode(), "Booster Run", Style::Fullscreen);

	//A VertexArray to holld all our graphics.
	VertexArray canvas(Quads, 0);

	//This can hold dispatch events to any object.
	InputDispatcher inputdispatcher(&window);

	// Everything will be a game object.
	// This vector will hold them all;
	vector <GameObject> gameObjects;

	// This class has all the knowlege to counstruct game object that do many different tings
	Factory factory(&window);

	// This call will send the vector of game objects
	// the canvas to draw on and the input dispatcher
	// to the factory to set up the game.
	factory.loadLevel(gameObjects, canvas, inputdispatcher);

	// A clock for timing
	Clock clock;

	// The color we use for the background
	const Color BACKGROUND_COLOR(100, 100, 100, 255);

	// This is the game loop.
	// We do not need to add to it.
	// Look how short and simple it is
	while (window.isOpen())
	{
		// Mesure the time taken this frame
		float timeTakenInSeconds = clock.restart().asSeconds();

		// Handle the player input.
		inputdispatcher.dispatchInputEvents();

		// Clear the previous frame.
		window.clear(BACKGROUND_COLOR);

		// Update all the game objects. !!!!
		for (auto& gameObject : gameObjects)
		{
			gameObject.update(timeTakenInSeconds);
		}

		// Draw all the game bojects to the canvas
		for (auto& gameObject : gameObjects)
		{
			gameObject.draw(canvas);
		}

		// Temporary code until next chapter
		window.draw(canvas, factory.m_Texture);

		// Show the new frame.
		window.display();
	}

	return 0;
}