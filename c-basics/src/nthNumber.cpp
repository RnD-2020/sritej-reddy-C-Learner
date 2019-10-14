/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci()
nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/
bool isprime(int num)
{
	if (num == 2)
		return true;
	for (int i = 2; i <= num / 2 + 1; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}
int nthFibonacci(int n)
{
	if (n <= 0)
	{
		return -1;
	}
	int p_prev = 0, prev = 1, temp;
	if (n == 1)
		return p_prev;
	if (n == 2)
		return prev;
	for (int i = 3; i <= n; i++)
	{
		temp = prev;
		prev = p_prev + prev;
		p_prev = temp;
	}
	return prev;
}

int nthPrime(int num)
{
	if (num <= 0)
	{
		return -1;
	}
	int count = 2, i = 3, prime;
	while (count <= num)
	{
		if (i % 2 != 0)
			if (isprime(i))
			{
				prime = i;
				count++;
			}
		i++;
	}
	return prime;
}
