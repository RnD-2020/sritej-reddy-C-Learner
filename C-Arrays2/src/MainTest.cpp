/*
Well Done for completing the first part of the C Course ,If you didnt finish
Do complete them and come here again .

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include "FunctionHeadersArrays2.h"
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int main(){

	//Test countGreaterNumbers

	//Test findSingleOccurenceNumber

	//Test mergeSortedArray

	//Test sortedArraysCommonElements

	//Test others
	int A[7] = { 2, 2, 2, 3, 6, 6, 6 };
	findSingleOccurenceNumber(A, 7);
	return 0;
}