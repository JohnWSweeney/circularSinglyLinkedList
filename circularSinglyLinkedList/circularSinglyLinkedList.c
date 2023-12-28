#include "circularSinglyLinkedList.h"
// sweeney's hand-rolled circular singly linked list.
//
// pos = "position".
// ptr = "pointer".
//
// error codes:
// 0	no error.
// 1	list is NULL.
// 2	ptr is NULL.
// 5	list has only one node.
// -1	pos/ptr not in list.
// -2	no action needed.

struct node* init(int data)
{
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = newNode;
	return newNode;
}

int print(struct node* list)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	int tempPos = 0;
	printf("#\tdata:\tlist:\t\t\tnext:\n");
	do {
		printf("%d\t%d\t%p\t%p\n", tempPos, list->data, list, list->next);
		++tempPos;
		list = list->next;
	} while (list != head);
	printf("\n");
}