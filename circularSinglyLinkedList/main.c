#include "csList.h"

int main()
{
	printf("Circular Singly Linked List v0.0.2\n\n");

	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position = 0;
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
	data = 1024;
	result = returnDataPos(list, data, &position);
	printf("Result: %d\n", result);
	printf("Data %d found in position %d.\n\n", data, position);
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