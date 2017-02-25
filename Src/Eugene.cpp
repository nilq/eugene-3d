

//Implementation include
#include "Eugene.h"

//Project includes
#include "Types.h"
#include "Texture.h"

//External includes
#include <SFML/System/Clock.hpp>

namespace egn
{
	//Constructor
	EugeneEngine::EugeneEngine()
	{
	}

	//Destructor
	EugeneEngine::~EugeneEngine()
	{
	}

	//Starts running the game
	void EugeneEngine::start()
	{
		sf::Clock timer;

		//The amount that the game is behind by, specified in microseconds(us)
		uint64 lag = 0;

		while (!this->shouldEnd)
		{
			lag += timer.restart().asMicroseconds();
			// 1/60th of a second isn't an exact number of microseconds, so this will be off by 1 second around every 50 minutes, which is negligible
			while (lag > 16667) {
				lag -= 16667;
				this->update();
			}
			this->render();
		}
	}

	//Updates the game
	void EugeneEngine::update()
	{
	}

	//Renders the game
	void EugeneEngine::render()
	{
	}


} //eugene

void main()
{
	egn::EugeneEngine instance;
	instance.start();
}