#pragma once

//Standard includes
#include <cstdint>

//External includes
#include <SFML/System/String.hpp>

//The different bit sizes
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

//Double and float are standard, so use those for floating point values

//SFML's string is useful for Unicode strings
typedef sf::String string;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;