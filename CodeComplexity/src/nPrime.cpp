/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 : it is running for 3ms

Way 2 :it is also running for 3ms - 2ms..I think it is taking same time because time is consumed for checking whether it is even or not

Way 3: it is only checking with obtained prime numbers..but still taking more time 760ms

Conclusion :Numbers other than prime that are less than given numbers will not divide the given number if primes under given numbers won't divide it.  
so we will only check with prime numbers obtained till now i.e that are less than given number
*/

#include <stdio.h>
#include <math.h>
#include<stdlib.h>

/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
bool isPrime(int n)
{
	for (int i = 2; i < n / 2 + 1; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int* nPrimeBruteForce(int N)
{
	int *a = (int *)malloc(N * sizeof(int));
	*a = 2;
	for (int i = 3,j=1; i < N; i++)
	{
		if (isPrime(i))
			*(a + j++) = i;
	}
	/*For every value of i it is running a loop to check if it is a prime or not
	it very time consuming*/
	return a;
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	int *a = (int *)malloc(N * sizeof(int));
	*a = 2;
	for (int i = 3, j = 1; i < N; i++)
	{
		if (i % 2 != 0  && isPrime(i))
			*(a + j++) = i;
	}
	/*In this for every value of i first it is checking whether it is even or not if no
	then then checks for prime
	There is no much noticable difference between this function and bruteforce ones because
	checking of whether a number is even or not is done for every ele which is not in bruteforce ones*/
	return a;
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
bool notDivisibleByObtainedPrime(int *a, int size,int n)
{
	for (int i = 0; i < size; i++)
	{
		if (n%*(a + i) == 0)
			return false;
	}
	return true;

}
int* nPrimeOptimized(int N)
{
	int *a = (int *)malloc(N * sizeof(int));
	*a = 2;
	for (int i = 3, j = 1; i < N; i++)
	{
		if (notDivisibleByObtainedPrime(a,j,i))
			*(a + j++) = i;
	}
	/*This logic really decreases the no.of divisions done but for me I am getting more time consumed
	for this one. I don't know why!*/
	return a;
}