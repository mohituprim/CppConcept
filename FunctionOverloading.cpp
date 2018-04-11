#include "FunctionOverloading.h"
#include <iostream>
using namespace std;

//Function overloading is a feature in C++ where two or more functions can have the same name but different parameters.
FunctionOverloading::FunctionOverloading(void)
{
}


FunctionOverloading::~FunctionOverloading(void)
{
}

/*	Functions that cannot be overloaded in C++
		-Function declarations that differ only in the return type.
		-Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is  a static member function declaration.
		-Parameter declarations that differ only in a pointer * versus an array [] are equivalent. That is, the array declaration is adjusted to become a pointer declaration. Only the second and subsequent array dimensions are significant in parameter types. For example, following two function declarations are equivalent.
			int fun(int *ptr);
			int fun(int ptr[]); // redeclaration of fun(int *ptr)
		-Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent.

			void h(int ());
			void h(int (*)()); // redeclaration of h(int())
		-Two parameter declarations that differ only in their default arguments are equivalent.
		-C++ allows member methods to be overloaded on the basis of const type.
			void fun() const{}
			void fun() {}
		-C++ allows functions to be overloaded on the basis of const-ness of parameters only if the const parameter is a reference or a pointer. 
			// Example 1 (Fails in compilation)
				void fun(const int i){}
				void fun(int i){}
			// Example 2 (Compiles and runs fine)
				void fun(char *a){}
				void fun(const char *a){}
*/

//Does overloading work with Inheritance?
//		Example 1 C++
class Base
{
public:
	int f(int i)
	{
		cout << "f(int): ";
		return i+3;
	}
};
class Derived : public Base
{
public:
	double f(double d)
	{
		cout << "f(double): ";
		return d+3.3;
	}
};
void FunctionOverloading::Overloading_main()
{
	Derived* dp = new Derived;
	cout << dp->f(3) << '\n';
	cout << dp->f(3.3) << '\n';
	delete dp;
}
//Overloading doesn�t work for derived class in C++ programming language. 
//There is no overload resolution between Base and Derived. The compiler looks into the scope of Derived, finds the single function �double f(double)� and calls it. 
//It never disturbs with the (enclosing) scope of Base. In C++, there is no overloading across scopes � derived class scopes are not an exception to this general rule
/*		
Example 2 Java
	class Base
	{
		public int f(int i)
		{
			System.out.print("f (int): ");
			return i+3;
		}
	}
	class Derived extends Base
	{
		public double f(double i)
		{
			System.out.print("f (double) : ");
			return i + 3.3;
		}
	}
	class myprogram3
	{
		public static void main(String args[])
		{
			Derived obj = new Derived();
			System.out.println(obj.f(3));
			System.out.println(obj.f(3.3));
		}
	}
	-In Java overloading works across scopes contrary to C++. 
	Java compiler determines correct version of the overloaded method to be executed at compile time 
	based upon the type of argument used to call the method and parameters of the overloaded methods of both these classes receive the values of arguments used in call and executes the overloaded method.
Example 3 C#
	using System;                     
	class Base
	{
		public int f(int i)
		{
			Console.Write("f (int): ");
			return i + 3;
		}
	}
	class Derived : Base
	{
		public double f(double i)
		{
			Console.Write("f (double) : ");
			return i+3.3;
		}
	} 
	class MyProgram
	{   
		static void Main(string[] args)
		{
			Derived obj = new Derived();
			Console.WriteLine(obj.f(3));
			Console.WriteLine(obj.f(3.3));
			Console.ReadKey(); // write this line if you use visual studio
		}
	}
	-Like C++, there is no overload resolution between class Base and class Derived. In C#, there is no overloading across scopes derived class scopes are not an exception to this general rule. This is same as C++ because C# is designed to be much closer to C++

*/

//Can main() be overloaded in C++?
//	To overload main() function in C++, it is necessary to use class and declare the main as member function. Note that main is not reserved word in programming languages like C, C++, Java and C#.