/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>
void swap(int *Arr, int index1, int index2)
{
	int t = Arr[index1];
	Arr[index1] = Arr[index2];
	Arr[index2] = t;
}
void * sortedArrayPositionsChange(int *Arr, int len)
{
	if(!Arr || len<1)
		return NULL;
	int index1=-1, index2=-1,i;
	for (i = 0; i < len; i++)
	{
		if (i == 0) //
		{
			if (Arr[i] > Arr[i + 1])
				index1 = i;
		}
		else if (i == len - 1)
		{
			if (Arr[i] < Arr[i - 1])
			{
				index2 = i;
			}
		}
		else if (Arr[i - 1] < Arr[i + 1])
		{
			if (Arr[i] > Arr[i + 1] && Arr[i] > Arr[i - 1]) //ele greater than its both side ele's
			{
				index1 = i;
			}
			else if (Arr[i] < Arr[i - 1] && Arr[i] < Arr[i + 1]) //ele smaller than its both side ele's
			{
				index2 = i;
			}
		}

		if (index1 != -1 && index2 != -1) //if both swapped ele's pos are captures into index1 and index2 then break
			break;
	}
	swap(Arr, index1, index2);
}