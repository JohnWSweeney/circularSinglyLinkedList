#include "csList.h"

int main()
{
	printf("Circular Singly Linked List v0.0.3\n\n");

	int result = 0;
	int nodeCount = 0;
	int data = 0;
	int position = 0;
	struct node* list = NULL;
	struct node* ptr = NULL;

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
	position = 0;
	result = returnPosPtr(list, position, &ptr);
	printf("Result: %d\n", result);
	printf("Position %d address: %p.\n\n", position, ptr);
	///
	result = returnPtrData(list, ptr, &data);
	printf("Result: %d\n", result);
	printf("Data: %d\n\n", data);
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