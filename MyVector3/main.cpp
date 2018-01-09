/// <summary>
/// Your name here
/// estimate
/// time spent
/// issues
/// 
/// </summary>
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "MyVector3.h"
#include <SFML\Graphics.hpp>
#include <string>



// Bart was here

int main()
{
	// Result bool
	bool equality{ false };
	// Vector one
	MyVector3 vectorOne{ 2.5,4.0,3.0 };
	// Vector two
	MyVector3 vectorTwo{ -2.5,6.0,4.5 };
	// Vector three
	MyVector3 vectorThree{ 0.0,0.0,0.0 };
	// Scalar value
	double scalar{ 3.0 };
	// Divisor value
	double divisor{ 2.0 };
	// Result value
	double result{ 0.0 };



	// Double constructor
	std::cout << "Constructor:" << std::endl;
	std::cout << vectorOne.toString() << std::endl;
	std::cout << "[2.5, 4.0, 3.0]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Equality Check
	equality = vectorOne.operator==(vectorTwo);
	std::cout << "Equality:" << std::endl;
	if (equality)
	{
		std::cout << "The vectors are equal." << std::endl;
	}
	equality = vectorOne.operator!=(vectorTwo);
	if (equality)
	{
		std::cout << "The vectors are not equal." << std::endl;
	}
	std::cout << "----------------------------" << std::endl;

	// Add operator
	vectorThree = vectorOne.operator+(vectorTwo);
	std::cout << "Addition:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[0.0, 10.0, 7.5]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Sub operator
	vectorThree = vectorOne.operator-(vectorTwo);
	std::cout << "Subtraction:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[5.0, -2.0, -1.5]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Scalar operator
	vectorThree = vectorOne.operator*(scalar);
	std::cout << "Scalar:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[7.5, 12.0, 9.0]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Divisor operator
	vectorThree = vectorOne.operator/(divisor);
	std::cout << "Divisor:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[1.25, 2.0, 1.5]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Plus/equals perator
	vectorThree = vectorOne;
	vectorThree.operator+=(vectorTwo);
	std::cout << "Plus/Equals:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[0.0, 10.0, 7.5]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Minus/equals operator
	vectorThree = vectorOne;
	vectorThree.operator-=(vectorTwo);
	std::cout << "Minus/Equals:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[5.0, -2.0, -1.5]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Negative of a vector
	vectorThree = vectorOne.operator-();
	std::cout << "Negative vector:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[-2.5, -4.0, -3.0]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Lenght of a vector
	result = vectorOne.length();
	std::cout << "Lenght:" << std::endl;
	std::cout << result << std::endl;
	std::cout << "5.59017" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Lenght squared of a vector
	result = vectorOne.lengthSquared();
	std::cout << "Lenght squared:" << std::endl;
	std::cout << result << std::endl;
	std::cout << "31.25" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Dot Product oftwo vectors
	result = vectorOne.dot(vectorTwo);
	std::cout << "Dot product:" << std::endl;
	std::cout << result << std::endl;
	std::cout << "31.25" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Cross product
	vectorThree = vectorOne.crossProduct(vectorTwo);
	std::cout << "Cross product:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "[0.0, -18.25, 25.0]" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Angle between
	result = vectorOne.angleBetween(vectorTwo);
	std::cout << "Angle between:" << std::endl;
	std::cout << result << std::endl;
	std::cout << "0.0" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Unit
	vectorThree = vectorOne.unit();
	std::cout << "Unit:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Normalise
	vectorThree = vectorOne;
	vectorThree.normalise();
	std::cout << "Normalise:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Projection
	vectorThree = vectorOne.projection(vectorTwo);
	std::cout << "Projection:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "----------------------------" << std::endl;

	// Rejection 
	vectorThree = vectorOne.rejection(vectorTwo);
	std::cout << "Rejection:" << std::endl;
	std::cout << vectorThree.toString() << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::system("pause");
	return EXIT_SUCCESS;
}


