/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algorithms.h
 * Author: mohituprim
 *
 * Created on 1 April, 2018, 7:00 PM
 */

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class Algorithms
{
public:
	Algorithms(void);
	~Algorithms(void);
	int BinarySearch(int*, int, int, int);
	int BubbleSort(int *input, int N);
	int SelectionSort(int *input, int N);
	void InsertionSort(int *input, int N);

	void QuickSort(int *input, int low, int high);
	int PartitionQuick(int *input, int low, int high);

	void MergeSort(int *input, int low, int high);
	void Merge(int *input, int low, int mid, int high);

	void HeapSort(int *input, int N);
	void Heapify(int *input, int N, int index);


};



#endif /* ALGORITHMS_H */

