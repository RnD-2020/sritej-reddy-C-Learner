/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1 : this is taking around 2ms

Way 2 :this is taking around 30ms while it shouldtake less time than 1st one

Way 3: this is taking 45ms but it should take less time than other two functions

Conclusion : As all even numbers will be divided by 2 we can eliminate checking with even numbers by dividing them with 2
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number){
	for (int i = 2; i < number; i++)
	{
		if (number%i == 0)
			return false;
	}
	/*this function wastes time in checking with numbers after square root of given number*/
	return 1;
}

/*
Is checking division till number neccesary? 

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
#include<math.h>
int isPrimeSquareRoot(int number){
	int number_sqrt = sqrt(number);
	for (int i = 2; i < number_sqrt; i++)
	{
		if (number%i == 0)
			return 0;
	}
	/*this func will not waste time in checking as that of first func but wastes time in checking with even numbers
*/
	return 1;
}

/*
Add more optimizations you like, 
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number){
	int N_sqrt = sqrt(number);
	if (number % 2 == 0)
		return 0;
	for (int i = 3; i < N_sqrt ; i+=2)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}
	/*this func will only check for non-even numbers only, This reduces the loop execution time*/
	return 1;
}


