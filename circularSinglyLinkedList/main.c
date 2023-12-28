#include "circularSinglyLinkedList.h"

int main()
{
	printf("Circular Singly Linked List v0.0.1\n\n");

	int result = 0;
	int nodeCount = 0;
	struct node* list = NULL;

	for (int i = 0; i < 9; i++)
	{
		addBack(&list, pow(i, 5));
	}
	result = size(list, &nodeCount);
	if (result == 0)
	{
		printf("Node count: %d\n", nodeCount);
	}
	else
	{
		printf("List is empty.\n");
	}
	print(list);
	/// test code here: ////////////////////////////////////////
	
	printf("Result: %d\n\n", result);
	////////////////////////////////////////////////////////////
	result = size(list, &nodeCount);
	if (result == 0)
	{
		printf("Node count: %d\n", nodeCount);
	}
	else
	{
		printf("List is empty.\n");
	}
	print(list);
}