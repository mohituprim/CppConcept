#include <cstdlib>
#include <cstdint>
#include "BitAlgo.h"
#include <set>
#include <iostream>
using namespace std;

BitAlgo::BitAlgo(void)
{
}


BitAlgo::~BitAlgo(void)
{
}

void BitAlgo::FindElementThatOccurrOddTimes(int *input, int N){
//Question 1 - Find the Number Occurring Odd Number of Times
	int element=0;
	for(int i=0; i<N; i++)
	{
		element ^=input[i];
	}
	cout<<element;
}

void BitAlgo::FindElementThatAppearsOnce(int *input, int N)
{
	

	//Question 2 -Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once
	int result=0;
	int sum, x;
        //INT_SIZE=32
	for(int i=0;i<32; i++)
	{
		sum=0;
		x =(1<<i);
		for(int j=0;j<N;j++)
		{
			if(input[j]&&x)
				sum++;
		}

		if(sum%3)
			result |=x;
	}
	cout<< result;
        
        
        //Another solution
        //Array [] : [a, a, a, b, b, b, c, c, c, d]
        //Mathematical Equation = ( 3*(a+b+c+d) – (a + a + a + b + b + b + c + c + c + d) ) / 2

        //In more simple words: ( 3*(sum_of_array_without_duplicates) – (sum_of_array) ) / 2
        set<int> *s = new set<int>();
        int sum_of_array=0;
        for(int i=0; i<N; i++)
        {
            s->insert(input[i]);
            sum_of_array +=input[i];
        }
        
        set<int>::const_iterator it; 
        int sum_of_unique_element=0;
        for(it=s->begin();it!=s->end(); it++)
            sum_of_unique_element +=*it;
        
        cout<<((3*sum_of_unique_element)-sum_of_array)/2;

}