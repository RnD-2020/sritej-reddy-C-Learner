/*
Overview:
Given an array of N points 
calculate the average and return the value in interger type

don't change the function signature!
for invalid cases return -1
*/
#include<stdlib.h>

int averageOfN(int* arr, int N)
{

	if (!arr || N<=0)
		return -1;
	double avg = 0;
	for (int i = 0; i < N; i++)
	{
		avg+= ((double)arr[i]/N);
	}
	return (int) avg;
}