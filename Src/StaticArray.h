#pragma once

//Project includes
#include "Types.h"

//Standard includes
#include <array>

namespace util
{
	//StaticArray - An array of static size
	template<typename T, uint32 Length>
	class StaticArray
	{
	public:
		
		//Constructor
		StaticArray();

		//Returns the size of the array
		uint32 size();

		//Pushes the element onto the array
		void push(T element);

		//Array operator: Access the element at index
		T& operator[](uint32 index);

	private:
		std::array<T, Length> arr;
	};

	//Returns the size of the array
	template<typename T, uint32 Length>
	inline uint32 StaticArray<T, Length>::size()
	{
		return this->arr.size();
	}

	//Array operator: Access the element at index
	template<typename T, uint32 Length>
	inline T& StaticArray<T, Length>::operator[](uint32 index)
	{
		this->arr[index];
	}

} //util