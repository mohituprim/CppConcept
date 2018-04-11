/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: mohituprim
 *
 * Created on 6 April, 2018, 11:12 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

//Implementation using structure for list
//struct AdjListNode
//{
//	int weight;
//	AdjListNode *next;
//};
//
//struct AdjList
//{
//	AdjListNode *head;
//};
//
//class Graph
//{
//private:
//	int V;
//	struct AdjList *array;
//public:
//	Graph(int);
//	AdjListNode * NewAdjListNode(int);
//	void AddEdge(int, int);
//	void PrintGraph();
//};

//Implementation using built-in list.
#include<list>
#include<iostream>
using namespace std;
class Graph
{
private:
	int V;
	list<int> *adj; // Pointer to an array containing adjacency lists
	void DFSUtil(int, bool*);
	bool isCyclicUtil(int v, bool visited[], bool *recStack);
public:
	Graph(int);
	void AddEdge(int, int);
	void BFS(int);
	void DFS(int);
	bool isCyclic();
};

#endif /* GRAPH_H */

