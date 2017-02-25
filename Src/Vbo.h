#pragma once

//Project includes
#include "Types.h"
#include "DynamicArray.h"

//External includes
#include <GL/glew.h>

namespace egn
{
	//VboDataPriority - An enum that signifies the priority of the data of a VBO
	enum class VboDataPriority
	{
		//For static drawing, when the vertex data never changes
		staticDraw = GL_STATIC_DRAW,
		//For dynamic drawing, when the vertex data changes once per many draws
		dynamicDraw = GL_DYNAMIC_DRAW,
		//For stream drawing, when the vertex data changes almost every frame
		streamDraw = GL_STREAM_DRAW
	};

	//Vbo - Encapsulates a vertex buffer object
	class Vbo
	{
	public:

		//Constructs a new VBO with the given data
		Vbo(util::DynamicArray<float>& data, VboDataPriority priority = VboDataPriority::staticDraw);

		//Destructor
		~Vbo();

		//Calls glBindBuffer() on this VBO
		void bind();

		//Returns the OpenGL handle of this VBO
		GLuint getHandle();

		//Returns the vertex count, vertex size is the amount of floats per vertex
		uint32 getVertCount(uint32 vertSize);

		//Copy Constructor: Deleted
		Vbo(const Vbo& copy) = delete;

		//Assignment operator: Deleted
		Vbo& operator=(const Vbo& copy) = delete;

		//Uploads new data to the VBO
		void uploadData(util::DynamicArray<float>& data);

	private:
		//The OpenGL buffer handle
		GLuint buffer;
		//The vertex count
		uint32 floatCount;
		//The priority of the memory
		VboDataPriority priority;
	};
} //egn