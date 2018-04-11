#include "StructLinkedList.h"
#include <iostream>
using namespace std;
struct LinkedList* AddElementInLinkedListAtLast( struct LinkedList *head, int data)
{
	struct LinkedList *newnode = new LinkedList();
	if(head==NULL)
	{
		struct  LinkedList *head = new LinkedList();
		(head)->data=data;
		(head)->next=NULL;
		return head;
	}
	struct LinkedList * temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next=newnode;
	newnode->data=data;
	newnode->next=NULL;
	return head ;
	
}

LinkedList *InsertInLinkedList(int data,  LinkedList *head, int pos)
{
	LinkedList *temp = head;
	LinkedList *ll = new LinkedList();
	ll->data = data;
	ll->next = NULL;

	if(temp==NULL)
	{
		return ll;
	}
	
	if(pos==0)
	{
		ll->next=temp;
		return ll;
	}
	//will insert at last if position is grater than no of present element
	while(temp->next!=NULL&&pos>0)
	{
		temp = temp->next;
		pos--;
	}
	temp->next =ll;
	return head;
}

struct LinkedList* DeleteFromLinkedList(LinkedList* head, int pos)
{
	LinkedList* temp=head;
	if(temp==NULL)
		return temp;
	if(pos==0)
	{
		head=temp->next;
		free(temp);
		return head;
	}
	// Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<pos-1; i++)
         temp = temp->next;

	// If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return head;

	// Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    LinkedList *next = temp->next->next;

	   // Unlink the node from linked list
    free(temp->next);  // Free memory
 
    temp->next = next;  // Unlink the deleted node from list
	return head;
}

struct LinkedList* DeleteElementFromLinkedList(struct LinkedList *head, int key)
{
		struct LinkedList * temp = head;
		struct LinkedList * prev = NULL;
		if(temp->data==key)
		{
			head = head->next;
			delete temp;
                        return head;
		}
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				prev->next=temp->next;
				delete temp;
                                return head;
			}
			prev = temp;
			temp = temp->next;
		}
                return head;
}

void PrintLinkedList(LinkedList* head)
{
	LinkedList* temp=head;
	while(temp)
	{
		cout<<temp->data<<"<-";
		temp=temp->next;
	}
        
        cout<<endl;
}

//solution one is take two pointer and move on poiner by one and other by two but here take one pointer only i.e. mid pointer
//and move this pointer only if count is odd so that at the end of traversal mid move only half of the lis. 
struct  LinkedList* PrintMiddleOfListUsingOnePointer(struct LinkedList* head)
{

	struct LinkedList* mid=head;
	int count=0;
	while(head!=NULL)
	{
		if(count&1)
		{
			mid = mid->next;
		}
		head=head->next;
		count++;
	
	}

	return mid;
}


LinkedList* ReverseLinkedList(LinkedList* head)
{
	LinkedList* prev=NULL;
	LinkedList* curr=head;
	LinkedList* next;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
	return head;
}

void RecursivePairWiseLinkedListSwap(struct LinkedList* head)
{

	struct LinkedList* temp = head;
	if(temp!=NULL&&temp->next!=NULL)
	{
		int data=temp->data;
		temp->data=temp->next->data;
		temp->next->data=data;
		RecursivePairWiseLinkedListSwap(temp->next->next);
	}
}

//Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
//Output:  3->2->1->6->5->4->8->7->NULL. 

struct LinkedList* RecursivegroupsWiseLinkedListSwap(struct LinkedList* head, int k)
{

	struct LinkedList* current = head;
	struct LinkedList* next = NULL;
	struct LinkedList* prev = NULL;
	int count=0;
	while(current!=NULL&&count<k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if(next!=NULL)
		head->next = RecursivegroupsWiseLinkedListSwap(next , k);

	return prev;
}

struct LinkedList* RecursiveAlternateLinkedListSwap(struct LinkedList* head, int k)
{

	struct LinkedList* current = head;
	struct LinkedList* next = NULL;
	struct LinkedList* prev = NULL;
	int count=0;
	if(current!=NULL&&count<k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if(head!=NULL)
		head->next=current;

	count =0;
	while(count<k-1&&current!=NULL)
	{
		current=current->next;
		count++;
	}
	if(current!=NULL)
		current->next = RecursiveAlternateLinkedListSwap(next , k);

	return prev;
}

//10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40
struct LinkedList* RotateALinkedList(struct LinkedList* head, int k)
{
	if(k==0)
		return head;
	struct LinkedList* current =head;

	while(current!=NULL&&--k>0)
	{
		current=current->next;
	}
	if (current == NULL)
        return head;
	struct LinkedList* kthNode =current;
	while(current->next!=NULL)
		current=current->next;

	current->next=head;
	head=kthNode->next;
	kthNode->next = NULL;
	//prev->next=NULL;
	return head;

}