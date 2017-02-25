#pragma once

//External includes
#include <GL/glew.h>

namespace egn
{
	//Vao - Wraps an OpenGL VAO into a class
	class Vao
	{
	public:

		//Constructor
		Vao();

		//Destructor
		~Vao();

		//Copy Constructor: Deleted
		Vao(Vao& copy) = delete;

		//Assignment Operator: Deleted
		Vao& operator=(Vao& copy) = delete;

		//Returns the OpenGL handle
		GLuint getHandle();

		//Calls glBindVertexArray() on the internal OpenGL handle
		void bind();

	private:

		//The OpenGL handle of the VAO
		GLuint handle;

	};
} //egn