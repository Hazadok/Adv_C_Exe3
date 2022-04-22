#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

/***************** Stack ADT Implementation *****************/

int HowMany(Stack s);




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
	int hash_counter = 0;
	int i = 0;
	int counter = 0;
	Stack* s_temp = (Stack*)malloc(1 * sizeof(Stack));
	if (s_temp == NULL) //if allocation failed exit the program
	{
		exit(1);
	}
	initStack(s_temp);
	

	//loop that go over the sentence and print the letters. if the letter is # its enter into an inner loop which goes over the letter and push them into the stack while counting how meny leeters,and how many hashes we saw, then print whats insid the stack (LIFO)
	while (sentence[i] != '\0')
	{
		counter = 0;
		hash_counter = 0;
		if (sentence[i]=='#')
		{
			sentence ++;
			for (hash_counter = 0; hash_counter < 1;counter++)
			{
				
				if (sentence[i] == '#')
				{
					sentence ++;
					hash_counter++;

					for ( int j = 0; j < counter; j++)
					{
						printf("%c", pop(s_temp));
					
					}
					
				}
			 
				else
				{
					push(s_temp, sentence[i]);
					sentence++;
				}
			}
			

		}
		
		
		
		else
		{
			printf("%c", sentence[i]);
			sentence++;
		}
	}
	

	
		
		
		
		
		
		
		
	}

	
		
	

	








int isPalindrome(Stack* s)
{
	// add your code here
}






void rotateStack(Stack* s, int n)
{
	
	Stack s_temp3 = *s;
	
	
	int amount = HowMany(s_temp3);
	if (n <= 0|| n >= amount)
		return;
		
	int i = 0;
	


	

	Stack* s_temp1 = (Stack*)malloc(1 * sizeof(Stack));
	if (s_temp1 == NULL) //if allocation failed exit the program
	{
		exit(1);
	}

	Stack* s_temp2 = (Stack*)malloc(1 * sizeof(Stack));
	if (s_temp2 == NULL) //if allocation failed exit the program
	{
		exit(1);
	}

	initStack(s_temp1);
	initStack(s_temp2);

	
	while (s_temp3.head!= NULL)
	{
		

		if (i< (amount - n))
		{
			
			push(s_temp2, s_temp3.head->data);
		}
		
		else
		{
			push(s_temp1, s_temp3.head->data);
		}
	
		s_temp3.head = s_temp3.head->next;
		i++;
	
	}

	
	
	
	destroyStack(s);
	initStack(s);
	for (int j = 0; j < (amount-n); j++)
	{
		
		push(s, pop(s_temp2));
	    
	}
	
	for (int k = 0; k < n; k++)
	{
		push(s, pop(s_temp1));
       
	}
	
	
	
	
	
	 
	

	
	
	



	








	// add your code here
}








int HowMany(Stack s)
{
	Stack s_tmp = s;
	
	if (s_tmp.head == NULL)
	return 0;
	
	
	else if ((s_tmp.head != NULL))
	{
		s_tmp.head = s_tmp.head->next;
		return HowMany(s_tmp) + 1;
	} 
	
}
