/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StructLinkedList.h
 * Author: mohituprim
 *
 * Created on 3 April, 2018, 8:31 PM
 */

#ifndef STRUCTLINKEDLIST_H
#define STRUCTLINKEDLIST_H

#include <stdlib.h>
struct LinkedList
{
	int data;
	LinkedList *next;
};

//Insert element at given position
LinkedList* InsertInLinkedList(int data, LinkedList *head, int pos);

struct LinkedList* AddElementInLinkedListAtLast( struct LinkedList *head, int data);
//Delete element from given position
struct LinkedList* DeleteFromLinkedList(LinkedList* head, int pos);

struct LinkedList* DeleteElementFromLinkedList(LinkedList* head, int key);

void PrintLinkedList(LinkedList* head);

LinkedList* ReverseLinkedList(LinkedList* head);

struct  LinkedList* PrintMiddleOfListUsingOnePointer(struct LinkedList* head);

void RecursivePairWiseLinkedListSwap(struct LinkedList* head);
struct LinkedList* RecursivegroupsWiseLinkedListSwap(struct LinkedList* head, int k);
struct LinkedList* RecursiveAlternateLinkedListSwap(struct LinkedList* head, int k);
struct LinkedList* RotateALinkedList(struct LinkedList* head, int k);

//How to write C functions that modify head pointer of a Linked List?
	//1) Functions that do not modify the head pointer
	/*	void addXtoList(struct node *node, int x)
		{
			while(node != NULL)
			{
				node->data = node->data + x;
				node = node->next;
			}
		}*/ 
	//2) Functions that modify the head pointer
	//2.1) Make head pointer global: We can make the head pointer global so that it can be accessed and updated in our function. Following is C code that uses global head pointer.

		// global head pointer 
		/*struct node *head = NULL;*/
 
		// function to delete first node: uses approach 2.1
		//void deleteFirst()
		//{
		//	if(head != NULL)
		//	{
		//	   // store the old value of head pointer    
		//	   struct node *temp = head;
        
		//	   // Change head pointer to point to next node 
		//	   head = head->next; 
 
		//	   // delete memory allocated for the previous head node
		//	   free(temp);
		//	}
		//}

	//2.2) Return head pointer:
	//2.3) Use Double Pointer: This approach follows the simple C rule: if you want to modify local variable of one function inside another function, pass pointer to that variable. 
			//So we can pass pointer to the head pointer to modify the head pointer in our deleteFirst() function.

		// function to delete first node: uses approach 2.3
		//void deleteFirst(struct node **head_ref)
		//{
		//	if(*head_ref != NULL)
		//	{
		//	   // store the old value of pointer to head pointer
		//	   struct node *temp = *head_ref;
 
		//	   // Change head pointer to point to next node
		//	   *head_ref = (*head_ref)->next;
 
		//	   // delete memory allocated for the previous head node
		//	   free(temp);
		//	}
		//}

#endif /* STRUCTLINKEDLIST_H */

