  /// <summary>
/// Vector 3 class
/// your name here or no marks
/// </summary>
#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Defautl constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;	
}

// Double constructor of MyVector3
MyVector3::MyVector3(double t_x, double t_y, double t_z)
{
	x = t_x;
	y = t_y;
	z = t_z;
}

MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = (double)t_sfVector.x;
	y = (double)t_sfVector.y;
	z = (double)t_sfVector.z;
}

MyVector3::MyVector3(sf::Vector3i t_sfVector)
{
	x = (double)t_sfVector.x;
	y = (double)t_sfVector.y;
	z = (double)t_sfVector.z;
}

MyVector3::MyVector3(sf::Vector2i t_sfVector)
{
	x = (double)t_sfVector.x;
	y = (double)t_sfVector.y;
	z = 0.0;
}

MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	x = (double)t_sfVector.x;
	y = (double)t_sfVector.y;
	z = 0.0;
}

MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x = (double)t_sfVector.x;
	y = (double)t_sfVector.y;
	x = 0.0;
}
// Equality check
bool MyVector3::operator==(const MyVector3 t_right) const
{
	bool result = { x == t_right.x && y == t_right.y && z == t_right.z };
	return result;
}
// Inequality check
bool MyVector3::operator!=(const MyVector3 t_right) const
{
	bool result = { x != t_right.x && y != t_right.y && z != t_right.z };
	return result;
}
// Addition
MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}
// Subtraction
MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}
// Multiplication
MyVector3 MyVector3::operator*(const double t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}
// Division
MyVector3 MyVector3::operator/(const double t_divisor) const
{
	return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
}
// Plus/Equals addition
MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;

	return MyVector3(x, y, z);
}
// Minus/Equals operator
MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;

	return MyVector3(x, y, z);
}
// Negative vector
MyVector3 MyVector3::operator-()
{
	return MyVector3(-x, -y, -z);
}
// Length of a vector
double MyVector3::length() const
{
	// Lenght formula
	double lenght{ std::sqrt((x*x) + (y*y) + (z*z)) };
	return lenght;
}
// Length squared of a vector
double MyVector3::lengthSquared() const
{
	// Calculates lenght squared
	double lenghtSquared{ (x*x) + (y*y) + (z*z) };

	return lenghtSquared;
}
// Dot product of to vectors
double MyVector3::dot(const MyVector3 t_other) const
{
	// Calculates dot product
	double dotProduct{ (x * t_other.x) + (y * t_other.y) + (z * t_other.z) };

	return dotProduct;
}
// Cross product
MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	MyVector3 newVector{ 0.0,0.0,0.0 };
	// Calculates the x coordinate
	newVector.x = (y * t_other.z) - (t_other.y * z);
	// Calculates the y coordinate
	newVector.y = ((x * t_other.z) - (t_other.x * z)) * -1;
	// Calculates the z coordinate
	newVector.z = (x * t_other.y) - (t_other.x * y);

	return newVector;
}

// Angle between 
double MyVector3::angleBetween(const MyVector3 t_other) const
{
	// used to store the angle
	double angleBetween{ 0.0 };
	// Lenght of the first vector
	double lengthOne{ 0.0 };
	// Lenght of the second vector
	double lengthTwo{ 0.0 };
	// Dot product of two vectors
	double dotProduct{ 0.0 };
	// Holds the value of the bottom of the angle between formula
	double detBottom{ 0.0 };

	// Gest the lenght of the first vector
	lengthOne = length();
	// Gets the lenght of the second vector
	lengthTwo = t_other.length();
	// Gets the dot product of the two vectors
	dotProduct = dot(t_other);
	// Calculates the bottom of the formula
	detBottom = lengthOne * lengthTwo;
	// Calculates the angle between vectors
	angleBetween = std::acos(dotProduct / detBottom);

	return angleBetween;
}
// Unit vector
MyVector3 MyVector3::unit() const
{
	// Calculates vector lenght
	double vectorLength = length();
	// Calculates the unit vector and returns it
	return MyVector3(x / vectorLength, y / vectorLength, z / vectorLength);
}
// Normalise
void MyVector3::normalise()
{
	// Calculates vector lenght
	double vectorLenght = length();
	// Normalises the vector anc changes its values
	x /= vectorLenght;
	y /= vectorLenght;
	z /= vectorLenght;
	//
}
// Projection To be fixed
MyVector3 MyVector3::projection(const MyVector3 t_other) const
{
	// Calculates the dot product
	double dotProduct{ dot(t_other) };
	// Calculates the lenght of the first vector
	double vectorLenght{ length() };
	// Projects vector one onto vector two
	return MyVector3((dotProduct / vectorLenght) * (x / vectorLenght)
		, (dotProduct / vectorLenght) * (y / vectorLenght)
		, (dotProduct / vectorLenght) * (z / vectorLenght));
}
// Rejection To be fixed
MyVector3 MyVector3::rejection(const MyVector3 t_other) const
{
	double dotProductOne = dot(t_other);
	double dotProductTwo = dot(MyVector3(x, y, z));
	return MyVector3((t_other.x - ((dotProductOne / dotProductTwo) * x))
		, (t_other.y - ((dotProductOne / dotProductTwo) * x))
		, (t_other.z - ((dotProductOne / dotProductTwo) * x)));
}

