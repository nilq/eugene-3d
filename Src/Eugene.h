#pragma once




namespace egn
{
	//Forward declarations
	class GameService;

	//EugeneEngine - The class that contains the entire state of the engine
	class EugeneEngine
	{
	public:

		//Constructor
		EugeneEngine();

		//Destructor
		~EugeneEngine();

		//Copy constructor: Deleted
		EugeneEngine(EugeneEngine& copy) = delete;

		//Assignment operator: Deleted
		EugeneEngine& operator=(EugeneEngine& copy) = delete;

		//Starts running the game
		void start();

		//Updates the game
		void update();

		//Renders the game
		void render();
	private:
		//Whether or not the game should end
		bool shouldEnd = false;


	};
}