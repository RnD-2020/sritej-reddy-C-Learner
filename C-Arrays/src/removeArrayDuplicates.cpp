/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<malloc.h>

void leftRotate(int *dupElePos, int dupElePosLen,int *arr,int len)
{
	int k = 1;
	for (int i = dupElePos[0]; i+k < len; i++)
	{
		if (i + k == dupElePos[k])
		{
			k++;
		}
		else
		{
			arr[i] = arr[i + k];
		}
	}
}

int checkForDup(int *arr, int len,int index,int num)
{
	int count_of_duplicates = 0;
	int *dupElePositions = (int *)malloc(sizeof(int)),size=0;
	/*dupElePositions stores the positions of duplicates of num in arr
	 we are storing duplicate positions just to decrease leftrotations performed every time
	 if we do not store them then we should perform a left rotate every time we see a dup ele*/
	for (int i = index+1; i < len-count_of_duplicates; i++)
	{
		if (num == arr[i])
		{
			size++;
			dupElePositions = (int*)realloc(dupElePositions, sizeof(int)*size);
			dupElePositions[size - 1] = i;
		}
	}
	if(size)
		leftRotate(dupElePositions, size, arr, len);
	return size; //size is the count of no of dup's of given num
}

int removeArrayDuplicates(int *Arr, int len)
{
	if (!Arr || len < 1)
		return -1;
	int no_of_duplicates = 0;
	for (int i = 0; i < len-no_of_duplicates; i++)
	{
		no_of_duplicates += checkForDup(Arr, len-no_of_duplicates, i, Arr[i]);
	}
	return len-no_of_duplicates;
}
