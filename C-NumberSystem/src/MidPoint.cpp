//fill this funtion return interger value only
//don't change the signature
#include<stdio.h>
int midPoint(int a, int b)
{
	double d1 = (double)a / 2, d2 = (double)b / 2;
	d1 += d2;
	return (int)d1;
}