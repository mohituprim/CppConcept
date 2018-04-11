#include <stdlib.h>
#include "Graph.h"
#include <iostream>
using namespace std;

//Implementation using structure for list
//Graph::Graph(int v)
//{
//	this->V=v;
//	array = new AdjList[v];
//	for(int i=0;i<v;++i)
//	{
//		array[i].head=NULL;
//	}
//}
//AdjListNode* Graph::NewAdjListNode(int weight)
//{
//	struct AdjListNode *newNode = new AdjListNode();
//	newNode->weight=weight;
//	newNode->next=NULL;
//	return newNode;
//}
//
//void Graph::AddEdge(int u, int v)
//{
//	AdjListNode * newNode = NewAdjListNode(v);
//	newNode->next=array[u].head;
//	array[u].head=newNode;
//	newNode = NewAdjListNode(u);
//	newNode->next =array[v].head;
//	array[v].head=newNode;
//}
//
//void Graph::PrintGraph()
//{
//	int i;
//	for(i=0;i<V;++i)
//	{
//		AdjListNode *pCrawl =array[i].head;
//		cout<<"\n Adjacency list of vertex "<<i<<"\n head ";
//		while (pCrawl)
//        {
//			cout<<"-> "<<pCrawl->weight;
//            pCrawl = pCrawl->next;
//         }
//                cout<<endl;
//	}
//}

//Implementation using built-in list.//Implementation using built-in list

Graph::Graph(int v)
{
	this->V=v;
	adj=new list<int> [V];
}
void Graph::AddEdge(int u, int v)
{
	adj[u].push_back(v); // Add w to v�s list.
}

void Graph::BFS(int startVertex)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;

	list<int> queue;
	visited[startVertex]=1;
	queue.push_back(startVertex);

	list<int>::iterator i;

	while (!queue.empty())
	{
		int newnode = queue.front();
		for(i=adj[newnode].begin();i!=adj[newnode].end();++i)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(newnode);
			}
		}
	}

}
void Graph::DFSUtil(int v, bool *visisted)
{
	visisted[v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();++i)
		{
			if(!visisted[*i])
			{
				DFSUtil(*i, visisted);
			}
		}

}
void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	DFSUtil(v, visited);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}


