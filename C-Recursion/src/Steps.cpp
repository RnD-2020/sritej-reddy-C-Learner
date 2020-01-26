/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"
#include<stdlib.h>

int fact(int n,int a[]) //stores the k! in a[k] and return value if a[k] is already present
{
	if (n < 2)
		return 1;
	if (a[n] != 0)
		return a[n];
	a[n]=n*fact(n - 1, a);
	return a[n];
}

int getCount(int s,int a[],int no_of_twos)
{
	if ((s-(no_of_twos*2)) < 0)
		return 0;
	int no_of_ones = s - (no_of_twos * 2); //if we have 112 then no_of_ones will be equal to 2 (actually s=4, no_of_twos=1 so we get 4-(1*2) so 2
	int count = fact(no_of_ones+no_of_twos,a)/(fact(no_of_ones,a)*fact(no_of_twos,a));
	return count+getCount(s,a, ++no_of_twos);
}

int get_steps(int s)
{
	if (s == 0)
		return 0;
	int* a = (int *)calloc(s,sizeof(int));
	return 1+getCount(s,a,1);
}