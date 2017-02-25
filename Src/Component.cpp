//Implementation include
#include "Component.h"

namespace egn
{
	//Constructor
	Component::Component(string name, SceneObject* owner)
	{
		this->name = name;
		this->owner = owner;
	}

	//Returns the name of this component
	string Component::getName()
	{
		return this->name;
	}

	//Returns the SceneObject that owns this component
	SceneObject* Component::getOwner()
	{
		return this->owner;
	}
}

