/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/

void set_zero_at_correct_pos(struct node *temp,struct node *first_zero_ptr, struct node *first_one_ptr, struct node * first_two_ptr)
{
	if (!first_one_ptr && !first_two_ptr)
	{
		if (!first_zero_ptr)
			first_zero_ptr == temp;
	}
	else if (!first_two_ptr)
	{
		temp->data = 1;
		first_one_ptr->data = 0;
		if (!first_zero_ptr)
			first_zero_ptr == first_one_ptr;
		first_one_ptr = first_one_ptr->next;
	}
	else if (!first_one_ptr)
	{
		temp->data = 2;
		first_two_ptr->data = 0;
		if (!first_zero_ptr)
			first_zero_ptr =first_two_ptr;
		first_two_ptr = first_two_ptr->next;
	}
	else
	{
		temp->data = 2;
		first_two_ptr->data = 1;
		first_two_ptr = first_two_ptr->next;
		first_one_ptr = 0;
		if (!first_zero_ptr)
			first_zero_ptr == first_one_ptr;
		first_one_ptr = first_one_ptr->next;
	}
}

void set_one_at_correct_pos(struct node * temp,struct node *first_one_ptr, struct node *first_two_ptr)
{
	
	if (!first_two_ptr)
	{
		if (!first_one_ptr)
			first_one_ptr = temp;
	}
	else if (first_two_ptr)
	{
		temp->data = 2;
		first_two_ptr->data = 1;
		if (!first_one_ptr)
			first_one_ptr = first_two_ptr;
		first_two_ptr = first_two_ptr->next;
	}
}

void sll_012_sort_swapData(struct node **head){
	struct node *first_zero_ptr, *first_one_ptr, *first_two_ptr;
	struct node *temp = *head;
	while (temp)
	{
		if (temp->data == 0)
		{
			set_zero_at_correct_pos(temp, first_zero_ptr, first_one_ptr, first_two_ptr);
		}
		else if (temp->data == 1)
		{
			set_one_at_correct_pos(temp, first_one_ptr, first_two_ptr);
		}
		else if (!first_two_ptr)
			first_two_ptr = temp;
		temp = temp->next;
	}
}

///////////////////////////////////////////////////////////////////////////////
struct node * updateZeroPtr(struct node *temp, struct node ** first_zero_ptr, struct node * first_one_ptr, struct node *last_zero_ptr,struct node *last_one_ptr,struct node *last_two_ptr)
{
	if (last_zero_ptr)
	{
		last_zero_ptr->next = temp;
		last_zero_ptr = last_zero_ptr->next;
	}
	else
	{
		*first_zero_ptr = temp;
		last_zero_ptr = temp;
	}

	last_zero_ptr->next = first_one_ptr;
	return last_zero_ptr;
}

struct node * updateOnePtr(struct node *temp, struct node ** first_one_ptr, struct node * first_two_ptr, struct node *last_zero_ptr, struct node *last_one_ptr,struct node *last_two_ptr)
{
	if (last_one_ptr)
	{
		last_one_ptr->next = temp;
		last_one_ptr = last_one_ptr->next;
	}
	else
	{
		*first_one_ptr = temp;
		last_one_ptr = temp;
		if (last_zero_ptr)
			last_zero_ptr->next = last_one_ptr;
	}
	last_one_ptr->next = first_two_ptr;
	return last_one_ptr;
}

struct node * updateTwoPtr(struct node *temp, struct node ** first_two_ptr,struct node *last_zero_ptr, struct node *last_one_ptr, struct node *last_two_ptr)
{
	if (last_two_ptr)
	{
		last_two_ptr->next = temp;
		last_two_ptr = last_two_ptr->next;
	}
	else
	{
		*first_two_ptr = temp;
		last_two_ptr = temp;
		if (last_one_ptr)
			last_one_ptr->next = last_two_ptr;
	}
	last_two_ptr->next = NULL;
	return last_two_ptr;
}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){

	struct node *temp = *head, *t;
	//first_zero_ptr : holds the first node address of 0 as data containg node
	//last_zero_ptr : holds the last node address of 0 as data containg node
	//and same for first_one_ptr, last_one_ptr,first_two_ptr and last_two_ptr
	struct node *last_zero_ptr = NULL, *last_one_ptr = NULL, *last_two_ptr = NULL, *first_zero_ptr = NULL, *first_one_ptr = NULL, *first_two_ptr;
	while (temp)
	{
		t = temp->next;
		if (temp->data == 0)
		{
			last_zero_ptr = updateZeroPtr(temp, &first_zero_ptr, first_one_ptr, last_zero_ptr, last_one_ptr, last_two_ptr);
		}
		else if (temp->data == 1)
		{
			last_one_ptr = updateOnePtr(temp, &first_one_ptr, first_two_ptr, last_zero_ptr, last_one_ptr, last_two_ptr);
		}
		else
		{
			last_two_ptr = updateTwoPtr(temp, &first_two_ptr, last_zero_ptr, last_one_ptr, last_two_ptr);
		}
		temp = t;
	}

	//assigning the stating address of linked list to head
	if (first_zero_ptr)
		*head = first_zero_ptr;
	else if (first_one_ptr)
		*head = first_one_ptr;
	else *head = first_two_ptr;
}