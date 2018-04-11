/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include "STLExample.h"

using namespace std;

STLExample::STLExample(void)
{
}


STLExample::~STLExample(void)
{
}

void STLExample::Iterating_through_a_vector()
{
    vector<int> vect;
    for (int nCount=0; nCount < 6; nCount++)
        vect.push_back(nCount);
    vector<int>::const_iterator it; // declare an read-only iterator
    it = vect.begin(); // assign it to the start of the vector
    while (it != vect.end()) // while it hasn't reach the end
        {
        cout << *it << " "; // print the value of the element it points to
        it++; // and iterate to the next element
        }
	/////////////////////////////////////////sort and reverse/////////////////////////////////////////////

	sort(vect.begin(), vect.end()); // sort the list
 
    //vector<int>::const_iterator it; // declare an iterator
    for (it = vect.begin(); it != vect.end(); it++) // for loop with iterators
        cout << *it << " ";
 
    cout << endl;
 
    reverse(vect.begin(), vect.end()); // reverse the list
 
    for (it = vect.begin(); it != vect.end(); it++) // for loop with iterators
        cout << *it << " ";
 
    cout << endl;
}

void STLExample::Iterating_through_a_list(){
    list<int> li;
    //auto is like var of c#
    for (auto nCount=0; nCount < 6; nCount++)
        li.push_back(nCount);
 
    list<int>::const_iterator it; // declare an iterator
    it = li.begin(); // assign it to the start of the list
    while (it != li.end()) // while it hasn't reach the end
    {
        cout << *it << " "; // print the value of the element it points to
        it++; // and iterate to the next element
    }
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//The min_element and max_element algorithms find the min and max element in a container class:
	///////////////////////////////////////////////////////////////////////////////////////////////////
	//list<int>::const_iterator it; // declare an iterator
    it = min_element(li.begin(), li.end());
        cout << *it << " ";
    it = max_element(li.begin(), li.end());
        cout << *it << " ";

	/////////////////////////////////////////////////////////////////////////find (and list::insert)///////////////////////////////
	it = find(li.begin(), li.end(), 3); // find the value 3 in the list
    li.insert(it, 8); // use list::insert to insert the value 8 before it
    cout << endl;
}

//Keep sorted
void STLExample::Iterating_through_a_set(){
    set<int> myset;
    myset.insert(7);
    myset.insert(2);
    myset.insert(-6);
    myset.insert(8);
    myset.insert(1);
    myset.insert(-4);
 
    set<int>::const_iterator it; // declare an iterator
    it = myset.begin(); // assign it to the start of the set
    while (it != myset.end()) // while it hasn't reach the end
    {
        cout << *it << " "; // print the value of the element it points to
        it++; // and iterate to the next element
    }
 
    cout << endl;
}

//map - kept sorted internally to speed searches
void STLExample::Iterating_through_a_map(){
    map<int, string> mymap;
    mymap.insert(make_pair(4, "apple"));
    mymap.insert(make_pair(2, "orange"));
    mymap.insert(make_pair(1, "banana"));
    mymap.insert(make_pair(3, "grapes"));
    mymap.insert(make_pair(6, "mango"));
    mymap.insert(make_pair(5, "peach"));
 
    map<int, string>::const_iterator it; // declare an iterator
    it = mymap.begin(); // assign it to the start of the vector
    while (it != mymap.end()) // while it hasn't reach the end
    {
		cout << it->first << "=" <<it->second<<" ";
			//<< (ostream)it->second << " "; // print the value of the element it points to
        it++; // and iterate to the next element
    }
 
    cout << endl;
}

