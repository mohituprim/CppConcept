/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MutableExample.h
 * Author: mohituprim
 *
 * Created on 6 April, 2018, 8:30 AM
 */

#ifndef MUTABLEEXAMPLE_H
#define MUTABLEEXAMPLE_H
using namespace std;
#include <cstdlib>
#include <string>
class MutableExample
{
public:
	MutableExample(void);
	~MutableExample(void);
};

class Date{
	bool cache_valid;
	string cache;
	void compute_cache_value(); //fill cache

public:
	//from user's point of view string_rep does not chnage the state of its date so it should be a constant member function.On the other hand cache needs to be filled before it can be used.
	string string_rep() const;

};

class DateMutable{
	mutable bool cache_valid;
	mutable string cache;
	void compute_cache_value() const; //fill mutable cache

public:
	string string_rep() const;

};

#endif /* MUTABLEEXAMPLE_H */

