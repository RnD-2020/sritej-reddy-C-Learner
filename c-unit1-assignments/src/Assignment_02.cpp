
//
// Compute factorial of a given positive integer
// 0 <= n <= 100
//
// return value         - number of digits in n!
// factorialDigits[158] - digits of n!
//
int noOfDigits(int n)
{
	int count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return count;
}
void rightShift(int a[],int n,int pos)
{
	for (int i = n; i >= 0; i--)
	{
		a[i + pos] = a[i];
	}
	a[0] = 0;
}
int factorialOfN(int n, int factorialDigits[158]) {
	//i am stroing result in an array and at every iteration if carry occurs while multiplying the last
	// digits (first digit in array at position 0) then i am rightshifting by one place and appending that carry
	// at positon 0;
	factorialDigits[0] = 1;
	if (n == 0 || n == 1)
		return 1;
	int i = 0, count = 0, temp = 0, carry = 0;
	while (n>1)
	{
		count = i;
		while (i >= 0)
		{
			temp = (factorialDigits[i] * n) + carry;
			carry = temp / 10;
			factorialDigits[i] = temp % 10;
			if (i == 0 && carry)
			{
				int no_of_digits_in_carry = noOfDigits(carry);
				rightShift(factorialDigits, count,no_of_digits_in_carry);
				count+=no_of_digits_in_carry;
				while (carry)
				{
					factorialDigits[(no_of_digits_in_carry--) - 1] = carry % 10;
					carry /= 10;
				}
			}
			i--;
		}
		carry = 0;
		i = count;
		n--;
	}
	return count + 1;
}


//
// recamán’s sequence: "subtract if you can, otherwise add"
//
// a(0) = 0; for n > 0, a(n) = a(n-1) - n if positive and
// not already in the sequence, otherwise a(n) = a(n-1) + n.
//
// http://oeis.org/A005132
//
// Write a function to find the first n numbers in this sequence
// n >= 0
//
// e.g:
// 0 => {0}
// 2 => {0, 1, 3}
// 5 => {0, 1, 3, 6, 2, 7}
//
// Note:
// The sequence will contain (n + 1) terms.
//
bool checkIfEleInArray(int n,int size, int a[])
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == n)
			return false;
	}
	return true;
}
void recamanSequence(int n, int sequence[]) {
	sequence[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		sequence[i] = sequence[i - 1] - i;
		if (sequence[i] <= 0 || !checkIfEleInArray(sequence[i], i, sequence))
			sequence[i] += (2 * i);
	}
}
