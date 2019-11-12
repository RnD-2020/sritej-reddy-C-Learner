
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	if (!input || length<1)
		return 0;
	int max_pos = -1, max_neg = 0,positive_count=0,negative_count=0;
	for (int i = 0; i < length; i++)
	{
		if (input[i] < 0 && max_neg == 0) //this condition is for storing first occuring negative ele into max_neg;
		{
			negative_count = 1;
			max_neg = input[i];
		}
		else if (input[i] >= 0 && max_pos < input[i]) //this is for storing the highest positive value into max_pos;
		{
			positive_count = 1;
			max_pos = input[i];
		}
		else if (input[i]<0 && input[i]>max_neg) //this is for storing the smallest negative value into max_neg; 
			max_neg = input[i];
	}
	if (positive_count && negative_count)
		return max_pos + max_neg;
	return 0;
}