#pragma once

//Project includes
#include "../Types.h"

//External includes
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

namespace script
{
	//Forward declarations
	class Domain;

	//Assembly - The class encapsulating a Mono assembly
	class Assembly
	{
	public:

		//Constructor
		Assembly(string filepath, Domain* domain);

		//Destructor
		~Assembly();

		//Copy Constructor: Deleted
		Assembly(Assembly& copy) = delete;

		//Assignment Operator: Deleted
		Assembly& operator=(Assembly& copy) = delete;

	private:
		//The C pointer to the assembly
		MonoAssembly* assembly = nullptr;

		//The domain object
		Domain* domain = nullptr;
	};
}