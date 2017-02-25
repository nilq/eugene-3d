#pragma once

//Project includes
#include "SceneObject.h"
#include "DynamicArray.h"

namespace egn
{
	//Scene - A class that holds an entire scene
	class Scene
	{
	public:
		
		//Constructor
		Scene();

		//Destructor
		~Scene();

		//Copy Constructor
		Scene(Scene& copy) = delete;

		//Assignment Operator
		Scene& operator=(Scene& copy) = delete;

		//Gets called every game tick
		void update();

		//Gets called every frame
		void render();

	private:
		//A dynamic array of all the SceneObjects in the root of the scene
		util::DynamicArray<SceneObject*> rootObjects;
	};

}