#include <stdlib.h>
#include "StructStack.h"
#include <iostream>
using namespace std;
Stack* IntializeStack()
{
	Stack *stack = new Stack();
	stack->top=-1;
	return stack;
}

// Stack is empty when top is equal to -1
bool isEmpty(Stack* stack)
{   
	return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(Stack* stack, int item)
{
	stack->stackArray.push_back(item);
	stack->top++;
}

// Function to remove an item from stack.  It decreases top by 1
int pop(Stack* stack)
{
	int item =stack->stackArray[stack->top--];
	stack->stackArray.pop_back();
	return item;
}

// Function to get top item from stack
int peek(Stack* stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->stackArray[stack->top];
}

// A utility function to check if the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;

}

int inFixToPostFix(char *exp)
{
	int i, k;
	struct Stack *stk = IntializeStack();
	//check stack is created
	if(!stk)
		return -1;
	for(i=0, k=-1;exp[i];i++)
	{
		if(isOperand(exp[i]))
                {
                    k++;
                    exp[k]=exp[i];
                }
		else if(exp[i]=='(')
			push(stk, '(');
		else if(exp[i]==')')
		{
			while(!isEmpty(stk)&&peek(stk)!='(')
				exp[++k]=pop(stk);
			if(!isEmpty(stk)&&peek(stk)!='(')
				return -1;
			else
				pop(stk);
		}
		else // an operator is encountered
		{
			while(!isEmpty(stk)&&Prec(exp[i])<=Prec(peek(stk)))
				exp[++k]=pop(stk);
			push(stk, exp[i]);
		}
	}
	while(!isEmpty(stk))
		exp[++k] = pop(stk);
	exp[++k] ='\0';
}
 