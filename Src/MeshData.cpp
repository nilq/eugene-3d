#include "MeshData.h"

namespace egn
{
	//Constructs a new MeshData object that contains the position, texture and normal data given
	MeshData::MeshData(util::DynamicArray<float> pos, util::DynamicArray<float> tex, util::DynamicArray<float> normal)
	{
		this->posData = new Vbo(pos);
		this->texData = new Vbo(tex);
		this->normalData = new Vbo(normal);
	}

	//Destructor
	MeshData::~MeshData()
	{
		delete this->posData;
		delete this->texData;
		delete this->normalData;
	}

	Vbo* MeshData::getPosVbo()
	{
		return this->posData;
	}
	Vbo* MeshData::getTexVbo()
	{
		return this->texData;
	}
	Vbo* MeshData::getNormalVbo()
	{
		return this->normalData;
	}


}
