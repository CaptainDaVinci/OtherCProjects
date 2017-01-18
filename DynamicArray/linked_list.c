/*
 * linked_list.c
 *
 *  Created on: Oct 1, 2015
 *      Author: Zack
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct node *next;
} node;

typedef struct
{
	node *head;
	int numItems;
} IntegerLinkedList;


void insert(int value, IntegerLinkedList *list);

int removeElement(int value, IntegerLinkedList *list);

void outputList(IntegerLinkedList *list);


int main()
{

	IntegerLinkedList *numbers = malloc(sizeof(node));
	numbers->numItems = 0;
	numbers->head = NULL;


	outputList(numbers);
	printf("Number of items in the list: %i \n", numbers->numItems);

	insert(7, numbers);
	outputList(numbers);
	printf("Number of items in the list: %i \n", numbers->numItems);

	insert(2, numbers);
	outputList(numbers);
	printf("Number of items in the list: %i \n", numbers->numItems);

	insert(5, numbers);
	outputList(numbers);
	printf("Number of items in the list: %i \n", numbers->numItems);

	if(removeElement(8, numbers) == 0)
		printf(" 8 could not be removed\n");
	outputList(numbers);

	if(removeElement(2, numbers))
		printf("2 was removed:\n");

	outputList(numbers);
	printf("Number of items in the list: %i \n", numbers->numItems);

	if(removeElement(7, numbers))
		printf("7 was removed:\n");

	outputList(numbers);
	printf("Number of items in the list: %i \n", numbers->numItems);

	if(removeElement(5, numbers))
		printf("5 was removed:\n");

	outputList(numbers);
	printf("Number of items in the list: %i \n", numbers->numItems);

	if(removeElement(8, numbers) == 0)
		printf("8 was not removed\n");

	outputList(numbers);
	printf("Number of items in the list: %i \n", numbers->numItems);


	free(numbers);

	return 0;

}


void insert(int value, IntegerLinkedList *list)
{
	node *nd = (malloc(sizeof(node)));
	nd->data = value;
	nd->next = list->head;

	list->head = nd;

	list->numItems++;

}

// Value: item == to Value is going to be removed
// int return: !0 if removed, otherwise, 0.
int removeElement(int value, IntegerLinkedList *list)
{
	int r = 0;

	node *current = (malloc(sizeof(node)));
	node *previous = (malloc(sizeof(node)));

	if(list->head == NULL){
		free(current);
		free(previous);
		return 0;
	}

	current = list->head;
	previous = list->head;
	for(int i = 0; i < list->numItems; i++)
	{
		// Removing Head
		if(current->data == value && i == 0)
		{
			list->head = current->next;
			free(current);
			r++;
			list->numItems--;
			break;
		}
		else if(current->data == value)
		{
			previous->next = current->next;
			free(current);
			r++;
			list->numItems--;
			break;
		}
		else if(current->next != NULL){
			previous = current;
			current = current->next;
		}
		else
			break;
	}



	return r;
}

void outputList(IntegerLinkedList *list)
{
	node *current = malloc(sizeof(node));
	if(list->head == NULL){
		printf("List is empty!\n");
		free(current);
		return;
	}

	current = list->head;
	printf("{ ");
	for(int i = 0; i < list->numItems; i++)
	{
		if(current->next != NULL){
			printf("%i, ", current->data);
			current = current->next;
		}
		if(current->next == NULL)
		{
			printf("%i }\n", current->data);
			return;
		}

	}


}

