#pragma once

//Project includes
#include "Vector3.h"
#include "DynamicArray.h"

namespace egn
{

	//Forward declarations
	class Component;

	//SceneObject - An object inside the scene
	class SceneObject
	{
	public:

		//Constructor
		SceneObject();
		
		//Destructor
		~SceneObject();

		//Copy Constructor: Deleted
		SceneObject(SceneObject& copy) = delete;

		//Assignment Operator: Deleted
		SceneObject& operator=(SceneObject& copy) = delete;

		//Gets called every game tick
		void update();

		//Gets called every frame
		void render();

	private:

		//A list of all the components of this object
		util::DynamicArray<Component*> components;

		//A list of all the children of this object
		util::DynamicArray<SceneObject*> children;

		util::Vector3d position;
		util::Vector3d rotation;
	};
}