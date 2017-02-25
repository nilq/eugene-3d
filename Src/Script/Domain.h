#pragma once

//Project includes
#include "../Types.h"

//External includes
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

namespace script
{

	//Domain - A class that wraps the Mono domain
	class Domain
	{
	public:

		//Loads the file with the given path and creates a new Mono domain with it
		Domain(string path);

		//Destructor
		~Domain();

		//Copy Constructor: Deleted
		Domain(Domain& copy) = delete;

		//Assignment Operator: Deleted
		Domain& operator=(Domain& copy) = delete;

		//Returns the C pointer to the MonoDomain
		MonoDomain* getPointer();

	private:
		//The C pointer to the domain
		MonoDomain* domain = nullptr;
	};

} //script