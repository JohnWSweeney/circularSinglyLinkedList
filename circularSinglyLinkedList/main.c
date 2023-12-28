#include "circularSinglyLinkedList.h"

int main()
{
	printf("Circular Singly Linked List v0.0.0\n\n");

	int result;
	struct node* list = NULL;
	/// test code here: ////////////////////////////////////////
	list = init(1234);
	result = print(list);
	printf("Result: %d\n", result);
	////////////////////////////////////////////////////////////
}