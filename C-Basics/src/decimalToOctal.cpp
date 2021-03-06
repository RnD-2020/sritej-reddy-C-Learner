/*
OVERVIEW:
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int decimalToOctal(int num)
{
	if (num < 0)
		return 0;
	int octal = 0, count = 0, temp = 0, tenpow = 1;
	while (num>0)
	{
		temp = num % 8;
		octal = octal + (temp*tenpow);
		tenpow *= 10;
		num /= 8;
		count++;
	}

	return octal;
}


float decimalToOctalFraction(float num)
{
	if (num < 0)
	{
		return 0;
	}
	float octal = decimalToOctal(num);
	float fractional_part = num - (int)num;
	fractional_part *= 8;
	octal += (int)fractional_part / 10;
	fractional_part -= (int)fractional_part;
	fractional_part *= 8;
	octal += (int)fractional_part / 10;
	return octal;
}

