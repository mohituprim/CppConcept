/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: mohituprim
 *
 * Created on 4 April, 2018, 8:51 AM
 */

#ifndef STACK_H
#define STACK_H
#include <vector>
using namespace std;

struct Stack
{
	int top;
	vector<int> stackArray;
};

Stack* IntializeStack();
bool isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
int inFixToPostFix(char *exp);

#endif /* STACK_H */

