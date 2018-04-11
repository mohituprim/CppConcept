/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algorithm.cpp
 * Author: mohituprim
 *
 * Created on 1 April, 2018, 6:59 PM
 */

#include <cstdlib>
#include "Algorithms.h"

using namespace std;

/*
 * 
 */


Algorithms::Algorithms(void)
{
}


Algorithms::~Algorithms(void)
{
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int Algorithms::BinarySearch(int *input, int element, int low, int high)
{
	if(high>=low){
		int mid = low+((high-low)/2);
		if(input[mid]==element)
			return mid;
		if(input[mid]>element)
			return BinarySearch(input, element, low, mid-1);
		return BinarySearch(input, element, mid+1, high); 
	}
	return -1;
}

//Sorting In Place: Yes
//Stable: Yes
int Algorithms::BubbleSort(int *input, int N)
{
	//int input[]= {10,2,18};
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N-i-1;j++){
			if(input[j]>input[j+1])
			{
				int temp=input[j];
				input[j]=input[j+1];
				input[j+1]=temp;
			}
		}
	}
}

//Sorting In Place
//The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation
int Algorithms::SelectionSort(int *input, int N)
{
	for(int i=0;i<N;i++)
	{
		int min = i;
		for(int j=i+1;j<N;j++)
		{
			if(input[j]>input[min])
				min = j;
		}
		swap(&(input[min]), &(input[i]));
	}
}


//Sorting In Place
//*Online - can sort a list at runtime
//*Stable - doesn't change the relative order of elements with equal keys.
void Algorithms::InsertionSort(int *input, int N)
{
	for(int i=1;i<N;i++)
	{
		int key=input[i];
		int j=i-1;
		while(j>=0&&input[j]>key)
		{
			input[j+1]=input[j];
			j=j-1;
		}
		input[j+1]=key;
	}
}

int Algorithms::PartitionQuick(int *input, int low, int high)
{
	int pivot = input[high];

	int i=low-1;

	for(int j=low;j<high; j++)
	{
		if(input[j]<=pivot)
		{
			i++;
			swap(&input[j], &input[i]);
		}
	}
	swap(&input[i+1], &input[high]);
	return i+1;
}

// in-place sort
//Quick Sort is also a cache friendly sorting algorithm as it has good locality of reference when used for arrays
void Algorithms::QuickSort(int *input, int low, int high)
{
	if(low<high)
	{
		int mid = PartitionQuick(input, low, high);
		QuickSort(input, low, mid-1);
		QuickSort(input, mid+1, high);
	}
}

void Algorithms::Merge(int *input, int low, int mid, int high)
{
	int n1 = mid-low+1;
	int n2 =high-mid;
	int *left = new int[n1];
	int *right = new int[n2];

	for(int i=0;i<n1;i++)
	{
		left[i]=input[low+i];
	}
	for(int j=0;j<n2;j++)
	{
		right[j]=input[mid+1+j];
	}

	int i=0;
	int j=0;
	int k=low;

	while(i<n1&&j<n2)
	{
		if(left[i]<=right[j])
		{
			input[k]=left[i];
			i++;
		}
		else{
			input[k]=right[j];
			j++;

		}
		k++;
	}

	while(i<n1)
	{
		input[k]=left[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		input[k]=right[j];
		j++;
		k++;
	}

}

//Auxiliary Space: O(n)
//Sorting In Place: No in a typical implementation
//Stable: Yes
void Algorithms::MergeSort(int *input, int low, int high)
{
	if(low<high)
	{
		int mid = ((unsigned)low+(unsigned)high)>>1;
		MergeSort(input, low, mid);
		MergeSort(input, mid+1, high);

		Merge(input, low, mid, high);
	}
}

void Algorithms::Heapify(int *input, int N, int index)
{

	int largest = index;
	int left = 2*index+1;
	int right = 2*index+2;

	if(left<N&&input[left]>input[largest])
		largest = left;
	if(right<N&&input[right]>input[largest])
		largest = right;

	if(largest!=index)
	{
		swap(&input[index], &input[largest]);

		Heapify(input, N, largest);
	}
}

//Heap sort is an in-place algorithm.
//Its typical implementation is not stable, but can be made stable
void Algorithms::HeapSort(int *input, int N)
{
	//Build Heap
	for(int i=N/2-1;i>=0;i--)
	{
		Heapify(input, N, i);
	}

	// One by one extract an element from heap
	for(int i=N-1;i>=0;i--)
	{
		// Move current root to end
		swap(&input[0], &input[i]);

		// call max heapify on the reduced heap
		Heapify(input, i, 0);
	}
}


