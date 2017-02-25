#pragma once

//Standard includes
#include <unordered_map>

//Project includes
#include "Types.h"


namespace util
{
	//HashMap<K, V> - K is the key type, and V is the value type
	template<typename K, typename V>
	class HashMap
	{
	public:

		//Constructor
		HashMap();

		//Returns the size of the array
		uint32 size();

		//Adds a key-value pair
		void add(K key, V value);

		//Removes the element with the given key
		void remove(K key);

		//Array operator: Access the element with the key key
		V& operator[](K key);

	private:
		std::unordered_map<K, V> map;
	};

	//Constructor
	template<typename K, typename V>
	inline HashMap<K, V>::HashMap()
	{
	}

	//Returns the size of the array
	template<typename K, typename V>
	inline uint32 HashMap<K, V>::size()
	{
		return this->map.size();
	}

	//Adds a key-value pair
	template<typename K, typename V>
	inline void HashMap<K, V>::add(K key, V value)
	{
		this->map[key] = value;
	}

	//Removes the element with the given key
	template<typename K, typename V>
	inline void HashMap<K, V>::remove(K key)
	{
		this->map.erase(key);
	}

	//Array operator: Access the element with the key key
	template<typename K, typename V>
	inline V& HashMap<K, V>::operator[](K key)
	{
		return this->map[key];
	}
} //util