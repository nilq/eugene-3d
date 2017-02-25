#pragma once

//Project includes
#include "Vbo.h"
#include "DynamicArray.h"

namespace egn
{

	//MeshData - Keeps all the data for a given mesh, only the vertices, however
	class MeshData
	{
	public:
		//Constructs a new MeshData object that contains the position, texture and normal data given
		MeshData(util::DynamicArray<float> pos, util::DynamicArray<float> tex, util::DynamicArray<float> normal);

		//Destructor
		~MeshData();

		//Copy Constructor
		MeshData(MeshData& copy) = delete;

		//Assignment Operator
		MeshData& operator=(MeshData& copy) = delete;

		//Return the different attributes of the mesh
		Vbo* getPosVbo();
		Vbo* getTexVbo();
		Vbo* getNormalVbo();

	private:

		//The different data VBOs
		Vbo* posData;
		
		Vbo* texData;
		Vbo* normalData;
	};

}