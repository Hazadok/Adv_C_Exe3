#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

//typedef struct charNode {
//	char data;
//	struct charNode* next;
//} charNode;
//
//
//typedef struct Stack {
//	charNode* head;
//} Stack;


void main()
{
	charNode* node = (charNode*)malloc(1 * sizeof(charNode));
	if (node==NULL)
	{
		exit(1);
	}
	Stack* s = (Stack*)malloc(1*sizeof(Stack));
	if (s==NULL)
	{
		exit(1);
	}
	
	initStack(s);
	int is_empty = isEmptyStack(s);
	printf("%d\n", is_empty);
	
	
	char data = 'a';
	char data2 = 'b';

	
	push(s, data);
	printf("%c\n", s->head->data);
	push(s, data2);
	printf("%c\n", s->head->data);

	pop(s);
	printf("%c\n", s->head->data);
    
	int is_stil_empty = isEmptyStack(s);
	printf("%d\n", is_stil_empty);

}