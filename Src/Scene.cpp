//Implementation include
#include "Scene.h"

namespace egn
{
	//Constructor
	Scene::Scene()
	{
	}

	//Destructor
	Scene::~Scene()
	{
	}

	//Gets called every game tick
	void Scene::update()
	{
		for (uint32 i; i < this->rootObjects.size(); ++i)
		{
			this->rootObjects[i]->update();
		}
	}

	//Gets called every frame
	void Scene::render()
	{
		for (uint32 i; i < this->rootObjects.size(); ++i)
		{
			this->rootObjects[i]->render();
		}
	}

}