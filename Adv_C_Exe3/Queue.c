#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	intNode* current = q->head;
	intNode* scouter = NULL;
	while (current) {
		scouter = current->next;
		free(current);
		current = scouter;
	}
	initQueue(q);
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* temp = (intNode*)malloc(sizeof(intNode));
	if (!temp) exit(1);
	temp->data = data;
	temp->next = NULL;
	if (isEmptyQueue(q)) 
		q->head = temp;
	else {
		q->tail->next = temp;
		q->tail = temp;
	}
}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q)) {
		printf("queue is empty cannot dequeue\n");
		exit(0);
	}
	else {
		int res = q->head->data;
		q->head = q->head->next;
		return res;
	}
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == q->tail)
		return 1;
	else return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// add your code here
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
}