//Implementation include
#include "Domain.h"

namespace script
{
	//Loads the file with the given path and creates a new Mono domain with it
	Domain::Domain(string path)
	{
		this->domain = mono_jit_init("Eugene3D Scripting Environment");
	}

	//Destructor
	Domain::~Domain()
	{
		mono_jit_cleanup(this->domain);
	}

	//Returns the C pointer to the MonoDomain
	MonoDomain* Domain::getPointer()
	{
		return this->domain;
	}
}