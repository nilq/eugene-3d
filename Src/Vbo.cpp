//Implementation include
#include "Vbo.h"

//External includes
#include <GL/glew.h>

namespace egn
{
	//Constructs a new VBO with the given data
	Vbo::Vbo(util::DynamicArray<float>& data, VboDataPriority priority)
	{
		//Create and bind the buffer
		glGenBuffers(1, &this->buffer);
		glBindBuffer(GL_ARRAY_BUFFER, this->buffer);

		this->floatCount = data.size();
		this->priority = priority;

		glBufferData(GL_ARRAY_BUFFER, data.sizeInBytes(), data.getPtr(), (GLenum) priority);
	}

	//Destructor
	Vbo::~Vbo()
	{
		glDeleteBuffers(1, &this->buffer);
	}

	//Returns the vertex count, vertex size is the amount of floats per vertex
	uint32 Vbo::getVertCount(uint32 vertSize)
	{
		return this->floatCount / 3;
	}

	//Uploads new data to the VBO
	void Vbo::uploadData(util::DynamicArray<float>& data)
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
		this->floatCount = data.size();
	}

	//Returns the OpenGL handle of this VBO
	GLuint Vbo::getHandle()
	{
		return this->buffer;
	}

}