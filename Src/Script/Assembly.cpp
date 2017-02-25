//Implementation include
#include "Assembly.h"

//Project includes
#include "Domain.h"

namespace script
{
	//Constructor
	Assembly::Assembly(string filepath, Domain* domain)
	{
		this->assembly = mono_domain_assembly_open(domain->getPointer(), filepath.toAnsiString().c_str());
		this->domain = domain;
	}

	//Destructor
	Assembly::~Assembly()
	{
		mono_assembly_close(this->assembly);
	}
}