#include "OperatorOverloading.h"
#include <iostream>
using namespace std;

//Following operator can not be overloded because they take name , rather than value as their second operand
//scope resolution(::)
//member selection(.)
//member selection through pointer to menber(.*)
//some more are ...
//trenary conditional expression (?:)
//sizeof()
//typeid
OperatorOverloading::OperatorOverloading(void)
{
}


OperatorOverloading::~OperatorOverloading(void)
{
}

class Complex{

	double re, im;
public:
	Complex(double r, double i):re(r), im(i){}

	Complex operator+ (Complex);
	Complex operator* (Complex);
};

void OperatorOverloading::OpOverloading_main()
{
	Complex a = Complex(1, 3.1);
	Complex b = Complex(1.2, 2);
	Complex c=b;

//	a=b+c;//using shorthand // means b.operator+(c)
//	a= b.operator+(c); // using explicit call

}


//a binary operator can be defined by either a nonstatic member function taking one argument or a non member function taking two argument
//a unary operator can be defined by either a nonstatic member function taking no argument or a non member function taking one argument
//operator=, operator[], operator(), and operator-> must be non static member function, this ensure that their first operand will be lvalues
