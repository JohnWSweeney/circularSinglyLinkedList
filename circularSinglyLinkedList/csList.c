#include "csList.h"
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

int addFront(struct node** list, int data)
{
	if (*list == NULL) // initialize empty list.
	{
		*list = init(data);
		return 0;
	}

	// find tail node and insert new head node.
	struct node* head = *list;
	do {
		struct node* curr = *list;
		if (curr->next == head)
		{
			struct node* newNode = malloc(sizeof(struct node));
			newNode->data = data;
			curr->next = newNode; // insert new node b/w tail and head.
			newNode->next = head;
			*list = newNode; // assign new head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
}

int addBack(struct node** list, int data)
{
	if (*list == NULL) // initialize empty list.
	{
		*list = init(data);
		return 0;
	}

	struct node* head = *list; // remember head node address.
	do {
		struct node* curr = *list;
		if (curr->next == head)
		{
			struct node* newNode = malloc(sizeof(struct node));
			newNode->data = data;
			curr->next = newNode;
			newNode->next = head;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
}

int deleteFront(struct node** list)
{
	if (*list == NULL) return 1; // list is empty.

	struct node* head = *list;
	if (head->next == head) // check if list has only one node.
	{
		free(head);
		*list = NULL;
		return 0;
	}
	// find tail node, delete head node.
	do {
		struct node* curr = *list;
		if (curr->next == head)
		{
			curr->next = head->next;
			*list = head->next;
			free(head);
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
}

int deleteBack(struct node** list)
{
	if (*list == NULL) return 1; // list is empty.
	
	struct node* head = *list;
	if (head->next == head) // check if list has only one node.
	{
		free(head);
		*list = NULL;
		return 0;
	}
	// find, delete tail node.
	do {
		struct node* curr = *list;
		struct node* dummy = curr->next;
		if (dummy->next == head)
		{
			free(dummy);
			curr->next = head;
			*list = head;
			return 0;
		}
		*list = curr->next;
	} while (*list != head);
}

int returnPosPtr(struct node* list, int pos, struct node** ptr)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	int tempPos = 0;

	do {
		if (tempPos == pos)
		{
			*ptr = list;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1; // position not in list.
}

int returnFrontData(struct node* list, int* data)
{
	if (list == NULL) return 1; // list is empty.
	*data = list->data;
	return 0;
}

int returnBackData(struct node* list, int* data)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	do {
		if (list->next == head)
		{
			*data = list->data;
			return 0;
		}
		list = list->next;
	} while (list != head);
}

int returnPosData(struct node* list, int pos, int* data)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			data = list->data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1; // position not in list.
}

int returnPtrData(struct node* list, struct node* ptr, int* data)
{
	if (list == NULL) return 1; // list is empty.
	if (ptr == NULL) return 2; // pointer is null.

	struct node* head = list;
	do {
		if (list == ptr)
		{
			*data = list->data;
			return 0;
		}
		list = list->next;
	} while (list != head);
	return -1; // pointer not in list.
}

int updatePosData(struct node* list, int pos, int data)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	int tempPos = 0;
	do {
		if (tempPos == pos)
		{
			list->data = data;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1; // position not in list.
}

int returnDataPos(struct node* list, int data, int* pos)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	int tempPos = 0;
	do {
		if (data == list->data)
		{
			*pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return -1; // data not in list.
}

int returnMinPos(struct node* list, int* min, int* pos)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	int tempPos = 0;

	*min = list->data;
	*pos = tempPos;

	do {
		if (*min > list->data)
		{
			*min = list->data;
			*pos = tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return 0;
}

int returnMaxPos(struct node* list, int* max, int* pos)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	int tempPos = 0;

	*max = list->data;
	*pos = tempPos;

	do {
		if (*max < list->data)
		{
			*max = list->data;
			*pos = tempPos;
		}
		++tempPos;
		list = list->next;
	} while (list != head);
	return 0;
}

int returnTailPos(struct node* list, int* pos)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	int tempPos = 0;

	do {
		if (list->next == head)
		{
			*pos = tempPos;
			return 0;
		}
		++tempPos;
		list = list->next;
	} while (list != NULL);
}

int clear(struct node** list)
{
	if (*list == NULL) return 1; // list is empty.

	struct node* head = *list;
	do {
		struct node* dummy = *list;
		*list = dummy->next;
		free(dummy);
		if (dummy->next == head)
		{
			*list = NULL;
			return 0;
		}
	} while (*list != head);
}

int isEmpty(struct node* list)
{
	if (list == NULL) return 1; // list is empty.
	else return 0;
}

int size(struct node* list, int* nodeCount)
{
	if (list == NULL) return 1; // list is empty.

	struct node* head = list;
	*nodeCount = 0;
	do {
		++*nodeCount;
		list = list->next;
	} while (list != head);
	return 0;
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
	return 0;
}