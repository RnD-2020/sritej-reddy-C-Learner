
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<stdlib.h>

int isPrime(int n,int *arr,int size) //this checks with only obtained prime numbers till now
{
	for (int i = 0; i < size; i++)
	{
		if (n%arr[i] == 0)
			return 0;
	}
	return 1;
}

int * storeInArray(int *arr, int num, int size) //this just increases size of array and stores the value
{
	arr = (int*)realloc(arr, sizeof(int)*size);
	arr[size - 1] = num;
	return arr;
}

int * nPrime(int N)
{
	if (N < 2)
		return NULL;
	int *arr=(int *)malloc(sizeof(int)),k=1;
	arr[0] = 2;
	for (int i = 3; i <= N; i+=2) //i=i+2 avoids even numbers as i is starting from 3;
	{
		if (isPrime(i, arr, k))
		{
			k++;
			arr=storeInArray(arr, i,k);
		}
	}
	return arr;
}