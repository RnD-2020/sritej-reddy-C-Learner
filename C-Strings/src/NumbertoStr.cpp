/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<math.h>
int noOfDigits(int number)
{
	int n = 0;
	while (number)
	{
		n++;
		number /= 10;
	}
	return n;
}

void numToString(int num,char *str,int *j,int ten_power)
{
	while (num) //converts number to String
	{
		*(str + *j) = (num / ten_power) + '0';
		num %= ten_power;
		ten_power /= 10;
		*j += 1;
	}
}

void number_to_str(float number, char *str,int afterdecimal){
	int j = 0;
	if (number < 0)
	{
		*str = '-';
		j = 1;
		number *= -1;
	}
	int num = number;
	int no_of_digits = noOfDigits(num);
	int ten_power = pow(10, no_of_digits - 1);
	number = number - num;
	numToString(num, str, &j, ten_power);
	
	if (afterdecimal)
	{
		/*we bring the required number of decimal numbers to be converted to string into integer part */
		*(str + j++) = '.';
		ten_power = pow(10, afterdecimal);
		num = number*ten_power;
		ten_power /= 10;
		numToString(num, str, &j, ten_power);
	}
	*(str + j) = '\0';
}
