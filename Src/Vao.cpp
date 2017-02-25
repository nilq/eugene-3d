//Implementation include
#include "Vao.h"

namespace egn
{
	//Constructor
	Vao::Vao()
	{
		glGenVertexArrays(1, &this->handle);
	}

	//Destructor
	Vao::~Vao()
	{
		glDeleteVertexArrays(1, &this->handle);
	}

	//Returns the OpenGL handle
	GLuint Vao::getHandle()
	{
		return this->handle;
	}

	//Calls glBindVertexArray() on the internal OpenGL handle
	void Vao::bind()
	{
		glBindVertexArray(this->handle);
	}



} //egn