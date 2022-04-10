#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	charNode* scouter = NULL;
	charNode* current = s->head;

	while (current)
	{
		scouter = current->next;
		free(current);
		current = scouter;
	}
	
	s->head = NULL;
		
}

void push(Stack* s, char data)
{
	charNode* new_node = (charNode*)calloc(1, sizeof(charNode));
	if (new_node==NULL)
	{
		exit(1);
	}


	new_node->data = data;
	
	if (s->head == NULL)
	    s->head = new_node;

	
	else
	
	{
		new_node->next = s->head;
		s->head = new_node;
	}
}




char pop(Stack* s)
{
	char ex = s->head->data;
	charNode* current = s->head;
	s->head = s->head->next;
	free(current);

	return ex;
	
}





int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;

	else return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{

	// add your code here
}

int isPalindrome(Stack* s)
{
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}