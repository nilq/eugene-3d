//Implementation include
#include "SceneObject.h"

//Project includes
#include "Component.h"

namespace egn
{
	//Constructor
	SceneObject::SceneObject()
	{
	}

	//Destructor
	SceneObject::~SceneObject()
	{
	}

	//Gets called every game tick
	void SceneObject::update()
	{
		//First run all the components, then all the child objects
	}

	//Gets called every frame
	void SceneObject::render()
	{
		//First run all the components, then all the child objects
	}
}