#include <iostream>
using namespace std;

class Name{
	const char* s;
};


class Table{
	Name* p;
	size_t sz;
public:
	//constructor
	Table(size_t s=15){
		p=new Name[sz=s];
	}

	//deconstructor
	~Table(){delete []p;}

	//Copy constructor
	Table(const Table&);
	//copy assignment constructor
	Table& operator=(const Table&);

	Name* lookup(const char*);
	bool insert(Name*);
};


struct Tables
{
	int i;
	int vi[10];
	Table tl;
	Table vt[10];
};

//Here tt will be intialized using a generated default constructor that calls Table(15) for tt.tl and each element of tt.vt. On the other hand tt.i andd tt.vi are not intialized 
//because those objects are not class type
Tables tt;

//Because const and refernce must be intialize..a class containing const or reference members can not be default constructed unless the programmer explicitly supplies a constructor
struct X
{
	const int a;
	const int& e;
};

//X x; //error no default constructor for X

void copyConstructorProblemTest()
{
	//default constructor will be invoked
	Table t1;

	//default constructor will not be invoked because this variable was intialized by copying it.
 	Table t2=t1; //so we should define copy constructor for this

	//default constructor will be invoked
	Table t3;

	t3=t2; //we should define copy assignment constructor for this

	//but the problem is destructor will be called three times : once each for t1, t2, t3

	//such problem is avoided by defining what it means to copy a table
	//Table(const Table&);
	//Table& operator=(const Table&);

}

//Copy constructor
Table::Table(const Table& t)
{
	p = new Name[sz=t.sz];
	for(int i=0;i<sz;i++)
	{
		p[i]=t.p[i];
	}
}

//copy assignment constructor
Table& Table::operator=(const Table&t)
{

	if(this!=&t)
	{
		delete [] p;
		p = new Name[sz=t.sz];
		for(int i=0;i<sz;i++)
		{
			p[i]=t.p[i];
		}
	}
	return *this;

}

//As is almost alwayst the case, the copy constructor and the copy assigment differ considerably. The fundamental reason is that a copy constructor intializes unintialized memory, 
//copy assigment operator must correctly deal with a well constructed object

//Necessary member intialization

class club {
	string name;
	Table members;
	Table officers;
public:
	club(const string& n);
};

//The constructor of members of a class is called in the order in which the members are declared in the class

club::club(const string&n)
	//constructor calling would not follow the order of intializer list so better is to keep the order of declration here to avoid confusion
	:name(n), members(), officers()
{
}


//Member object of classes without default constructor
//const members
//reference members
//intialization is necessary
class M{

	const int i;
	club c;
	club& pc;
public:
	M(int ii, const string&n, club & c):i(ii), c(n), pc(c) {}
};

//copying members
//A default copy constructor or default copy assigment copies all element of a class. if this copy can not be done, it is an error to try to copy an object of such a class

class Unique_handle{

private:
	Unique_handle(const Unique_handle&);
	Unique_handle& operator=(const Unique_handle);
public:

};

struct Y{
	Unique_handle a; //require explicit intialization
};

//Y y1;
//Y y2=y1; //error can not copy y::a

//default assigment can not be generated if a nonstatic member is a refernce , a const , or a user defined type without a copy assigment


//Array Object
//if an object of a class can be constructed without supplying an explicit intializer, then arrays of that class can be defined
Table tbl[10];

