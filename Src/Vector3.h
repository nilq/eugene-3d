#pragma once

//Project includes
#include "Types.h"

//Standard includes
#include <cmath>

//External includes
#include <SFML/System.hpp>

namespace util
{
	//Axis enum for misc stuff
	enum class Axis
	{
		x, y, z
	};

	//Vector3 - A 3D vector
	template<typename T>
	struct Vector3
	{
	public:
		//X and Y
		T x;
		T y;
		T z;

		//Returns the magnitude of the vector
		T magnitude();

		//Normalizes the vector
		void normalize();

		//Rotates the vector along the X axis
		//deg - The amount(in degrees) to rotate the vector
		void rotateX(decimal deg);

		//Rotates the vector along the Y axis
		//deg - The amount(in degrees) to rotate the vector
		void rotateY(decimal deg);

		//Rotates the vector along the Z axis
		//deg - The amount(in degrees) to rotate the vector
		void rotateZ(decimal deg);

		//Constructor: Creates a Vector3 with the corresponding values
		Vector3(T x, T y, T z);

		//Constructor: Creates a Vector3 with the values at 0
		Vector3();

		//Constructor: Copy constructor
		Vector3(const Vector3& copy);

		//Implicit conversion between game vectors and SFML vectors
		Vector3(const sf::Vector3<T>& other);
		
		//Assignment operator
		Vector3<T> operator=(const Vector3& copy);

		//Equality comparison operator
		bool operator==(const Vector3& other);

		//Inequality comparison operator
		bool operator!=(const Vector3& other);
	};

	//Returns the magnitude of the vector
	template<typename T>
	inline T Vector3<T>::magnitude()
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}

	//Normalizes the vector
	template<typename T>
	inline void Vector3<T>::normalize()
	{
		T mag = this->magnitude();
		this->x *= mag;
		this->y *= mag;
		this->z *= mag;
	}

	//Rotates the vector along the X axis
	//deg - The amount(in degrees) to rotate the vector
	template<typename T>
	inline void Vector3<T>::rotateX(decimal deg)
	{
		decimal rad = (180 / pi) * deg;
		this->y = (cos(rad) * this->y) - (std::sin(rad) * this->z);
		this->z = (sin(rad) * this->y) + (std::cos(rad))
	}

	//Rotates the vector along the Y axis
	//deg - The amount(in degrees) to rotate the vector
	template<typename T>
	inline void Vector3<T>::rotateY(decimal deg)
	{
		decimal rad = (180 / pi) * deg;
		this->x = (cos(rad) * this->x) + (std::sin(rad) * this->z);
		this->z = ((sin(rad) * -1) * this->x) + (std::cos(rad) * this->z);
	}

	//Rotates the vector along the Z axis
	//deg - The amount(in degrees) to rotate the vector
	template<typename T>
	inline void Vector3<T>::rotateZ(decimal deg)
	{
		decimal rad = (180 / pi) * deg;
		this->x = (cos(rad) * this->x) - (sin(rad) * this->y);
		this->y = (sin(rad) * this->x) - (cos(rad) * this->y);
	}

	//Constructor: Creates a Vector3 with the corresponding values
	//X - The distance along the X axis
	//Y - The distance along the Y axis
	//Z - The distance along the Z axis
	template<typename T>
	inline Vector3<T>::Vector3(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	//Constructor: Creates a Vector3 with the values at 0
	template<typename T>
	inline Vector3<T>::Vector3() : Vector3<T>(T(), T(), T())
	{
	}

	//Constructor: Copy constructor
	template<typename T>
	inline Vector3<T>::Vector3(const Vector3& copy)
	{
		this->x = copy.x;
		this->y = copy.y;
		this->z = copy.z;
	}

	//Implicit conversion between game vectors and SFML vectors
	template<typename T>
	inline Vector3<T>::Vector3(const sf::Vector3<T>& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	//Assignment operator
	template<typename T>
	inline Vector3<T> Vector3<T>::operator=(const Vector3& copy)
	{
		if (&copy != this)
		{
			this->x = copy.x;
			this->y = copy.y;
			this->z = copy.z;
		}
		return *this;
	}

	//Equality comparison operator
	template<typename T>
	inline bool Vector3<T>::operator==(const Vector3& other)
	{
		return this->x == other.x && this->y == other.y && this->z == other.z;
	}

	//Inequality comparison operator
	template<typename T>
	inline bool Vector3<T>::operator!=(const Vector3 & other)
	{
		return this->x != other.x || this->y != other.y || this->z != other.z;
	}


	
	//Vector3 with int32s
	typedef Vector3<int32> Vector3i;
	//Vector3 with floats
	typedef Vector3<float> Vector3f;
	//Vector3 with decimals
	typedef Vector3<double> Vector3d;

} //util