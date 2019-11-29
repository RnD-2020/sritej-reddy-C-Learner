/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

void insertAtPos(int *Arr, int pos, int length,int num)
{
	for (int i = length - 1; i > pos; i--)
	{
		Arr[i] = Arr[i - 1];
	}
	Arr[pos] = num;
}

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (!Arr || len < 1)
		return NULL;
	int length = len + 1;
	Arr = (int*)realloc(Arr, sizeof(int)*(length));
	for (int i = 0; i < length; i++)
	{
		if (i == len)
		{
			insertAtPos(Arr, i, length,num);
		}
		else
		{
			if (Arr[i] > num)
				insertAtPos(Arr, i, length, num);
		}
	}
	return Arr;
}