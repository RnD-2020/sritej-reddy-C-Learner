/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

void linear_sort(struct node *head)
{
	struct node *temp = head,*t=NULL,*hold_temp=NULL;
	while (temp)
	{
		hold_temp = temp->next;
		while (hold_temp)
		{
			if (temp->num > hold_temp->num)
			{
				int t = temp->num;
				temp->num = hold_temp -> num;
				hold_temp->num = t;
			}
			hold_temp = hold_temp->next;
		}
		temp = temp->next;
	}
}

struct node * sortLinkedList(struct node *head) {
	if (!head)
		return NULL;
	linear_sort(head);
	return head;
}