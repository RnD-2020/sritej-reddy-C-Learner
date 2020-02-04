/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>


int findSingleOccurenceNumber(int *A, int len) {
	if (!A || len < 1) return 0;
	//copied from geeksforgeeks but understood
	int temp[8]={0}, res = 0,two_exp=1;
	for (int i = 0; i< len; i++)
	{
		for (int j = 0; j < 8; j++) {
			temp[j] += A[i] & 1;
			A[i] = A[i] >> 1;
		}
	}
	for (int i = 0; i < 8; i++) {
		temp[i] = temp[i] % 3;
		res += temp[i] * two_exp;
		two_exp *= 2;
	}
	return res;
}