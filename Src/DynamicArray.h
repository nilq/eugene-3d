#pragma once

//Standard includes
#include <vector>

//Project includes
#include "Types.h"

namespace util
{
	//DynamicArray<T> - A wrapper to std::vector<T>
	template<typename T>
	class DynamicArray
	{
	public:

		//Constructor
		DynamicArray();

		//Returns the size of the array
		uint32 size();

		//Returns the size of the array in bytes
		uint32 sizeInBytes();

		//Pushes the element onto the array
		void push(T element);

		//Pops from the end
		void pop();

		//Removes the element at the given index from the array
		void remove(uint32 index);

		//Returns T*, which is the very first element in the array, invalidated when the array is modified
		T* getPtr();

		//Array operator: Access the element at index
		T& operator[](uint32 index);

	private:
		std::vector<T> arr;
	};

	//Constructor
	template<typename T>
	inline DynamicArray<T>::DynamicArray()
	{
	}

	//Returns the size of the array
	template<typename T>
	inline uint32 DynamicArray<T>::size()
	{
		return this->arr.size();
	}

	//Returns the size of the array in bytes
	template<typename T>
	inline uint32 DynamicArray<T>::sizeInBytes()
	{
		return this->arr.size() * sizeof(T);
	}

	//Pushes the element onto the array
	template<typename T>
	inline void DynamicArray<T>::push(T element)
	{
		this->arr.push_back(element);
	}

	//Pops from the end
	template<typename T>
	inline void DynamicArray<T>::pop()
	{
		this->arr.pop_back();
	}

	//Removes the element at the given index from the array
	template<typename T>
	inline void DynamicArray<T>::remove(uint32 index)
	{
		this->arr.erase(i);
	}

	//Returns T*, which is the very first element in the array, invalidated when the array is modified
	template<typename T>
	inline T* DynamicArray<T>::getPtr()
	{
		return this->arr->data();
	}

	//Array operator: Access the element at index
	template<typename T>
	inline T& DynamicArray<T>::operator[](uint32 index)
	{
		return arr[index];
	}
}