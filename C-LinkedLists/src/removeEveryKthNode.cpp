/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * getPrevNode(struct node *head, int K)
{
	struct node * temp=head;
	while (K - 2>0 && temp!=NULL)
	{
		temp = temp->next;
		K--;
	}
	return temp;
}

void removeItsNextNode(struct node *temp)
{
	if(temp->next != NULL)
	temp->next = temp->next->next;
	else temp->next = NULL;
}

struct node * removeEveryKthNode(struct node *head, int K) {
	if (!head || K < 2)
		return NULL;
	struct node * temp = head,* t=head;
	int t_k=0;
	while (temp != NULL)
	{
		t_k++;
		if (t_k%K == 0)
		{
			temp = getPrevNode(t, K);
			t = temp;
			removeItsNextNode(temp);
			t = t->next;
		}
		temp = temp->next;
	}
	return head;
}