#pragma once

//Project includes
#include "Types.h"

namespace egn
{

	//Forward declarations
	class SceneObject;

	//Component - The base class for the component of a SceneObject
	class Component
	{
	public:

		//Constructor
		Component(string name, SceneObject* owner);

		//Copy Constructor: Deleted
		Component(Component& copy) = delete;

		//Assignment Operator: Deleted
		Component& operator=(Component& copy) = delete;

		//Returns the name of this component
		string getName();

		//Returns the SceneObject that owns this component
		SceneObject* getOwner();

		//Gets called every game tick
		virtual void update() = 0;

		//Gets called every frame
		virtual void render() = 0;
	protected:

		//The name of the component
		string name;

		//The SceneObject that is the owner of this component
		SceneObject* owner;

	};

}