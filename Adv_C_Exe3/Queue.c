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
	if (q == NULL) {
		puts("illigal queue\n");
		return;
	}
	if (isEmptyQueue(q))
		return;
	Queue* q1 = (Queue*)malloc(sizeof(*q));
	if (!q1) {
		puts("allocation failed\n");
	}
	else {
		int counter = 0;
		while (isEmptyQueue(q)){
			enqueue(q1, dequeue(q));
			counter++;
		}
		for (int i = 0; i < counter - 1; i++) 
			enqueue(q, dequeue(q1));
		for (int i = 0; i < counter - 1; i++)
			enqueue(q1, dequeue(q));
		for (int i = 0; i < counter; i++)
			enqueue(q, dequeue(q1));
	}
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	if (q == NULL) {
		puts("illigal queue\n");
		return;
	}
	if (isEmptyQueue(q))
		return;
	Queue* q1 = (Queue*)malloc(sizeof(*q));
	Queue* q2 = (Queue*)malloc(sizeof(*q));
	if (!q1||!q2) {
		puts("allocation failed\n");
	}
	int counter = 0, min = INT_MAX, check;
	while (!isEmptyQueue(q)) {
		check = dequeue(q);
		counter++;
		if (check < min)
			min = check;
		enqueue(q1, check);
	}
	
	for (int i = 0; i < counter; i++) {
		while (!isEmptyQueue(q1)) {
		    check = dequeue(q1);
			if (check <= min) {
				enqueue(q, check);
			}
			else {
				enqueue(q2, check);
			}
		}
		min = INT_MAX;
		while (!isEmptyQueue(q2)){
			check = dequeue(q2);
			if (check < min)
				min = check;
			enqueue(q1, check);
		}
	}
}