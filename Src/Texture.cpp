//Implementation include
#include "Texture.h"

namespace egn
{

	//Constructor
	Texture::Texture(string filepath)
	{
		//Load the image
		this->img = new sf::Image();
		this->img->create(100, 100);
		this->img->loadFromFile(filepath);

		//Create and assign a texture
		glGenTextures(1, &this->handle);
		
		glBindTexture(GL_TEXTURE_2D, this->handle);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->img->getSize().x, this->img->getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->img->getPixelsPtr());
	}

	//Destructor
	Texture::~Texture()
	{
		delete this->img;
		glDeleteTextures(1, &this->handle);
	}

}