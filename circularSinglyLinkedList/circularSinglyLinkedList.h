#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
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

struct node* init(int data);
int addFront(struct node** list, int data);
int addBack(struct node** list, int data);
int deleteFront(struct node** list);
int deleteBack(struct node** list);
int clear(struct node** list);
int isEmpty(struct node* list);
int size(struct node* list, int* nodeCount);
int print(struct node* list);