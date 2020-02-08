/*
Use MainLinkedLists1 File for testing any other function in other Cpp files of the Strings Project.
DO NOT write main function in any other File or else your Build Fails.s
Do not write same add,display function in every CppFile .VS throws an error if two files
have some functions with same signature.
You can either change the signature in each file by using add1,display2 like that or
keep a common header file which has functions for handling common tasks for debugging
like displaying and include that header file in each Problem file .
Only jump into this lesson after you did all specified functions in Tutorial Lesson.
Objectives of C-LinkedLists-1 Lesson:
->Add/Delete/Display nodes in SLL
->Manipulate Links in SLL
->Handling SLL which have nodes of more than one data field
*/


//Do not edit below Header Files
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersLinkedLists1.h"
#include "../src/SLL012Sort.cpp"

struct node * createNode1(int n1) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n1;
	newNode->next = NULL;
	return newNode;
}

struct node * add(struct node **head, int p) {
	struct node *temp = *head;
	if (*head == NULL) {
		(*head) = createNode1(p);
		(*head)->next = NULL;
		return *head;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = createNode1(p);
		temp->next->next = NULL;
		return temp->next;
	}
}

int check(int *nums, int len, struct node *head) {
	int index = 0;
	struct node *temp = head;
	for (index = 0; index < len; index++) {
		if (temp->data != nums[index]) {
			return  0;
		}
		temp = temp->next;
	}
	return 1;
}



int main(){

	//Test 012SortSll
	//Test numberToLinkedList
	//int num = 99999;
	//int A[] = { 9, 9, 9, 9,9 };
	//struct node *head = numberToLinkedList(num);
	//printf("\n\n\nn=%d",isDivisibleSLL(createSLLFromString("12345677"), 34078));
	//Test removeEveryKthNode
	
	//Test sortLinkedList

	//Test twodigitLinkedList

	//Test isDivSLL
	/*struct node *head = createList(42153);
	sortLinkedList(head);
	while (head)
	{
		printf("\n%d\n", head
		->num);
		head = head->next;
	}*/
	int num = 0;
	struct node *head = NULL;
	int num_array[100] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 2 };
	struct node *actualnodes[100];
	int actualNodeIndex = 0;
	int output[100] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 2 };
	int len = 10;
	int i = 0;
	for (i = 0; i<len; i++)
	{
		struct node * newNode = add(&head, num_array[i]);
		actualnodes[actualNodeIndex] = newNode;
		actualNodeIndex++;
	}
	sll_012_sort(&head);
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;

	}
	return 0;
}