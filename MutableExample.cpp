#include "MutableExample.h"
#include <cstdlib>
using namespace std;


MutableExample::MutableExample(void)
{
}


MutableExample::~MutableExample(void)
{
}

string Date::string_rep() const
{
	if(cache_valid==false)
	{
		Date* th = const_cast<Date*>(this); //cast away const
//		th->Date::compute_cache_value();
		th->cache_valid=true;
	}
	return cache;
}

//const_cast operator is used to obtain a pointer of type Date* to this. This is hardly elegant and it is not to work when applied to an object that was originally declared as a constant
//Date d1;
//const Date d2;
//string s1=d1.string_rep();
//string s2=d2.string_rep(); //undefined behaviour

//This problem can be avoided by declaring the data mutable 

string DateMutable::string_rep() const
{
	if(cache_valid==false)
	{
//		this->DateMutable::compute_cache_value();
		cache_valid=true;
	}
	return cache;
}