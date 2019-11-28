/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * createNode(int data)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->num = data;
	temp->next = NULL;
	return temp;
}

struct node * numberToLinkedList(int N) {
	if (N == 0)
		return createNode(0);
	if (N < 0)
		N *= -1;
	struct node *temp = NULL;
	while (N)
	{
		struct node *current_node = createNode(N%10);
		current_node->next = temp;
		temp = current_node;
		N /= 10;
	}
	return temp;
}