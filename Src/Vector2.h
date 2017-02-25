#pragma once

//Project includes
#include "Types.h"

//Standard includes
#include <cmath>

//External includes
#include <SFML/System.hpp>

namespace util
{
	//Vector2 - A 2D vector
	template<typename T>
	struct Vector2
	{
	public:
		//X and Y
		T x;
		T y;

		//Returns the magnitude of the vector
		T magnitude();

		//Normalizes the vector
		void normalize();

		//Rotates the vector
		//deg - The amount(in degrees) to rotate the vector
		void rotate(decimal deg);

		//Constructor: Creates a Vector2 with the corresponding values
		Vector2(T x, T y);

		//Constructor: Takes in an sf::Vector2<T> to create a conversion
		Vector2(const sf::Vector2<T>& other);

		//Constructor: Copy constructor
		Vector2(const Vector2& copy);

		//Assignment operator
		Vector2<T> operator=(const Vector2& copy);

		//Equality comparison operator
		bool operator==(const Vector2& other);

		//Inequality comparison operator
		bool operator!=(const Vector2& other);
	};

	//Returns the magnitude of the vector
	template<typename T>
	inline T Vector2<T>::magnitude()
	{
		return std::sqrt((x * x) + (y * y));
	}

	//Normalizes the vector
	template<typename T>
	inline void Vector2<T>::normalize()
	{
		T mag = this->magnitude();
		this->x *= mag;
		this->y *= mag;
	}

	//Rotates the vector
	//deg - The amount(in degrees) to rotate the vector
	template<typename T>
	inline void Vector2<T>::rotate(decimal deg)
	{
		decimal rad = (180 / pi) * deg;
		this->x = (std::cos(rad) * this->x) - (std::sin(rad) * y);
		this->y = (std::sin(rad) * this->x) + (std::cos(rad) * y);
	}

	//Constructor: Creates a Vector2 with the corresponding values
	template<typename T>
	inline Vector2<T>::Vector2(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	//Constructor: Copy constructor
	template<typename T>
	inline Vector2<T>::Vector2(const Vector2& copy)
	{
		this->x = copy.x;
		this->y = copy.y;
	}

	//Constructor: Takes in an sf::Vector2<T> to create a conversion
	template<typename T>
	inline Vector2<T>::Vector2(const sf::Vector2<T>& other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	//Assignment operator
	template<typename T>
	inline Vector2<T> Vector2<T>::operator=(const Vector2& copy)
	{
		//Check for self-assignment
		if (this != &copy)
		{
			this->x = copy.x;
			this->y = copy.y;
		}
		return *this;
	}

	//Equality comparison operator
	template<typename T>
	inline bool Vector2<T>::operator==(const Vector2& other)
	{
		return this->x == other.x && this->y == other.y;
	}

	//Inequality comparison operator
	template<typename T>
	inline bool Vector2<T>::operator!=(const Vector2& other)
	{
		return this->x != other.x || this->y != other.y;
	}

	//Vector2 with int32s
	typedef Vector2<int32> Vector2i;
	//Vector2 with floats
	typedef Vector2<float> Vector2f;
	//Vector2 with doubles
	typedef Vector2<double> Vector2d;

} //util