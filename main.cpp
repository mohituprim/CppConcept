/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mohituprim
 *
 * Created on 1 April, 2018, 6:57 PM
 */
#include <cstdlib>

#include "Algorithms.h"
#include "STLExample.h"
#include "DynamicAlgo.h"
#include "lambda.h"

#include "Creational/LSP.h"
#include "StructLinkedList.h"
#include "StructStack.h"
#include "BitAlgo.h"
#include "FunctionOverloading.h"
#include "OperatorOverloading.h"
#include "Tree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {


//    STLExample *st = new STLExample();
//    st->Iterating_through_a_vector();
//    st->Iterating_through_a_list();
//    st->Iterating_through_a_map();
//    st->Iterating_through_a_set();
   
//    lambda_main();
    
    int input[]= {10,2,18};
    //https://stackoverflow.com/questions/9012312/getting-c-error-conversion-to-non-scalar-type-requested/9012337
    //Algorithms a= new Algorithms();   //wrong 
    //a.BubbleSort(input, 3);   //wrong
    //Algorithms *a= new Algorithms();
    //a->BubbleSort(input, 3);

//    struct LinkedList *head = NULL;
//    head = InsertInLinkedList(10, head, 1);
//    head = InsertInLinkedList(20, head, 2);
//    head = InsertInLinkedList(30, head, 3);
//    head = InsertInLinkedList(40, head, 4);
//    head = InsertInLinkedList(50, head, 5);
//    head = InsertInLinkedList(60, head, 6);
//    
//    head = AddElementInLinkedListAtLast(head, 70);
//    
//    PrintLinkedList(head);
//    
//    //Position starting from 0
//    head = DeleteFromLinkedList(head, 0);
//    head = DeleteElementFromLinkedList(head, 20);
//    
//    PrintLinkedList(head);
//    
//    struct LinkedList* mid = PrintMiddleOfListUsingOnePointer(head);
//    
//    head = ReverseLinkedList(head);
//    PrintLinkedList(head);
//    RecursivePairWiseLinkedListSwap(head);
//    PrintLinkedList(head);
//    head = RecursivegroupsWiseLinkedListSwap(head, 3);
//    PrintLinkedList(head);
//    //Wrong need to be checked
//    //head = RecursiveAlternateLinkedListSwap(head, 2);
//    //PrintLinkedList(head);
//    head = RotateALinkedList(head, 2);
//    PrintLinkedList(head);
    
//    struct Stack* st = IntializeStack();
//    push(st, 10);
//    push(st, 20);
//    push(st, 30);
//    
//    int item =  pop(st);
//    item = peek(st); 
//    //char* exp = "(a*b)" is restricting to modify the expression
//    //https://stackoverflow.com/questions/27910782/modify-a-char-in-c
      //https://stackoverflow.com/questions/2444085/alternative-to-strdup
//    char exp[] = "(a*b)";
//    inFixToPostFix(exp);
//    
    
//    knapsack();
//    UnboundedKnapsack();
    
//    BitAlgo *b = new BitAlgo();
//    int inputOdd[] = {1,2,2,2,3,3,3};
//    //b->FindElementThatOccurrOddTimes(inputOdd, 5);
//    b->FindElementThatAppearsOnce(inputOdd, 7);
    
//    FunctionOverloading *fo = new FunctionOverloading();
//    fo->Overloading_main();
    
//      OperatorOverloading *oo = new OperatorOverloading();
//      oo->OpOverloading_main();
    //int a = LSP();
    
    
    Tree *b = new Tree();
    Node* root = b->IntializeBinaryTree();
    //b->printInorder(root);
    //b->printPostorder(root);
    //b->printPreorder(root);
    b->printLevelOrderUsingQueue(root);
    return 0;
}

