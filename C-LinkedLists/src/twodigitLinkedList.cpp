/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
};

int convert(struct twoDigitNode *head)
{
	struct twoDigitNode *temp = head;
	int num = 0;
	while (temp)
	{
		num = num * 10;
		num += temp->digit1;
		num = num * 10;
		num += temp->digit2;
		temp = temp->next;
	}
	return num;
}

int convert_sll_2digit_to_int(struct twoDigitNode *head){
	if (!head)
		return 0;
	int num = 0;
	num=convert(head);
	return num;
}
