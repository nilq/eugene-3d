#pragma once

//Project includes
#include "Types.h"

//External includes
#include <SFML/Graphics/Image.hpp>

#include <GL/glew.h>

namespace egn
{

	//Texture - An OpenGL texture
	class Texture
	{
	public:

		//Constructor
		Texture(string filepath);

		//Destructor
		~Texture();

		//Copy Constructor: Deleted
		Texture(Texture& copy) = delete;

		//Assignment Operator: Deleted
		Texture& operator=(Texture& copy) = delete;

		//Returns the image of this texture
		sf::Image* getImage();

		//Returns the OpenGL handle of this texture
		GLuint getHandle();

	private:

		//The handle of the image
		GLuint handle;

		//The image, used for loading as well
		sf::Image* img = nullptr;
	};
}