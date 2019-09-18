/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num <= 0)
	{
		return 0;
	}
	//convert octal to decimal
	int octtemp=0,dec=0;
	for (int i = 0; num > 0; i++)
	{
		octtemp = num % 10;
		dec += octtemp*pow(8, i);
		num /= 10;
	}
	int count = 0,hextemp=0,hex=0;
	while (dec)
	{
		hextemp = dec % 16;
		hex = hex + (hextemp*pow(10, count));
		dec /= 16;
		count++;
	}
	/*float temp;
	char *hex,*h,*rt;
	h = hex;
	int t;
	//convert dec to hex
	while (num<16)
	{
		temp = num % 16;
		temp -= (int)temp;
		temp = temp * 16;
		t = temp - (int)temp;

		if (t > 9)
		{
			switch (t)
			{
			case 10:*(hex++) = 'A';
				break;
			case 11:*(hex++) = 'B';
				break;
			case 12:*(hex++) = 'C';
				break;
			case 13:*(hex++) = 'D';
				break;
			case 14:*(hex++) = 'E';
				break;
			case 15:*(hex++) = 'F';
				break;
			}
		}
		else
			*(hex++) = (char)t;


	}
	rt = hex--;
	//as test case doesn't contain which gives char type of hex number as o/p so i am passing (int)
	return (int)hex;*/
	return hex;
}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}