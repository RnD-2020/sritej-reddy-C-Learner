/*
Note:
1. Read instructions for each function carefully.
2. Feel free to create new functions if needed. Give good names!
3. Check the reference links when ever given.
4. After solving the question and making corresponding test cases pass
   - reflect on where is the gap in your understanding, while solving the problem.
   - if you have to create a similar problem, how would you do/tweek it?
   - when your friends seek help, instead of explaining your logic,
     give hints to solve. Always.
*/

//
// butterfly number for the given integer
//
// e.g:
// 20  => "2002"
// -2  => "-22-"
//
// To get butterfly number for the given number 20,
// take its reversal 02 and join them to form "2002".
//
#include<math.h>
void butterflyNumber(int n, char butterfly[23]) {
	int t = n, no_of_digits = 0;
	// this loop counts the digits in given number
	while (t)
	{
		no_of_digits++;
		t /= 10;
	}
	//this condition is for n=0 only because above loop won't count if n==0
	if (no_of_digits == 0)
		no_of_digits = 1;
	//pos_back is used as index for filling n in reverse and pos_front for filling n in the same way 
	// ex:n=123 ans="123321" --first 123 is filled in reverse(3 2 1) using pos_back and 
	//next 321 is filled using pos_front
	int pos_back = no_of_digits - 1, pos_front = no_of_digits;
	//if n is negative we add - at starting and end 
	if (n < 0)
	{
		butterfly[0] = '-';
		butterfly[(2 * no_of_digits) + 1] = '-';
		butterfly[(2 * no_of_digits) + 2] = '\0';
		pos_back = no_of_digits;
		pos_front = no_of_digits + 1;
		n *= -1;
	}
	else
	{
		butterfly[2 * no_of_digits] = '\0';
	}
	while (no_of_digits--)
	{
		butterfly[pos_back--] = ((char)(n % 10))+'0';
		butterfly[pos_front++] = ((char)(n % 10))+'0';
		n /= 10;
	}
}

//
// Write a function that finds the positive integers up to 100
// that are palindromes in base b
//
// b > 1
//
// saves a list of base–10 numbers less than or equal to 100
// that are palindromic in base b.
// and return the count.
//
// e.g:
// 10 => { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99}, 18 palindromes
// 2  => { 1, 3, 5, 7, 9, 15, 17, 21, 27, 31, 33, 45, 51, 63, 65, 73, 85, 93, 99}, 19 palindromes
//
// Once you have completed this function, check this reference.
// Ref: http://www.worldofnumbers.com/nobase10.htm
//
#include<string.h>
bool ispalindrome(int a[], int n)
{
	for (int i = 0, j = n - 1; i < j; i++, j--)
	{
		if (a[i] != a[j])
			return false;
	}
	return true;
}

bool convertToBaseb(int b, int n, int a[])
{
	int i = 0;
	while (n)
	{
		a[i++] = n%b;
		n /= b;
	}
	return ispalindrome(a,i);
}
int palindromeNumbers(int b, int numbers[]) {
	// i am storing number converted into base b in a array
	int k = 0;
	int a[100];
	for (int i = 1; i <= 100; i++)
	{
		if (convertToBaseb(b, i, a))
		{
			numbers[k++] = i;
		}
	}
	return k;
}


//
// Write a function that finds the closest (to n) 5 positive integers
// that are even
//
// return a sorted list of assending order even numbers (greater than zero).
//
// Note:
// In case of conflict return the smallest number.
// let us say for the 5th element, 2 numbers are at same distance from n.
// then include the smallest of the 2 numbers.
//
// e.g:
// 14  => { 8, 10, 12, 16, 18}; // 8 and 20 are at equal distance from 14, we pick 8.
// 15  => { 10, 12, 14, 16, 18}; // 10 and 20 are at equal distance from 15, we pick 10.
//
// Ref: https://en.wikipedia.org/wiki/Parity_of_zero
//
// Note: You must return only numbers which are greater than zero.
//
void closest5EvenNumbers(int n, int evens[5]) {
	//i am taking i=2 and j=3 and using them as indexes 
	//then decrementing i and incrementing j
	//if suppose I get 0 while entering at i'th pos then I'll move the array generated till 
	// now towards left then j will be pointing at the position where next element can be added
	int t,k=0;
	if (n % 2 == 0)
		t = 2;
	else t = 1; 
	bool reached_zero = false;
	for (int i = 2, j = 3; i>-1 || j<5; i--, j++,t+=2)
	{
		if (!reached_zero )
		{
			if (n - t > 0)
			{
				evens[i] = n - t;
			}
			else
			{
				reached_zero = true;
				k = 0;
				i++;
				while (i != j)
				{
					evens[k++] = evens[i];
					i++;
				}
				j = k;
			}
		}
		if(j!=5)
			evens[j] = n + t;
	}
}

//
// Write a function that finds the closest 5 positive integers
// that are palindromes in base b.
//
// b > 1
//
// return a sorted list of assending order.
//
// Note:
// 1. In case of conflict return the smallest number.
//    let us say for the 5th element, 2 numbers are at same distance from n.
//    then include the smallest of the 2 numbers.
// 2. Palindromes must be greater than zero.
//    for i = 0 to 4, palindromes[i] > 0.
//
void rotate(int a[],int j,int flag)
{
	//in this function if flag=1 then it is rightshift else leftshift
	int i,t=1;
	if (flag)
	{
		i = j;
		j = 0;
		t = -1;
	}
	else {
		i = j;
		j = 5;
	}
	for (i; i!=j;i+=t)
	{
		a[i] = a[i + t];
	}
}
void closest5PalindromeNumbers(int n, int b, int palindromes[5]) {
	int t, k = 0;
	t = 1;
	bool reached_zero = false, enteredAtX = false, enteredAtY = false;
	int a[100];
	for (int i = 2, j = 3; i>-1 || j<5;t++)
	{
		enteredAtX = false;
		enteredAtY =false;
		if (!reached_zero && i>-1)
		{
			if (n - t > 0)
			{
				enteredAtX = true;
				if (convertToBaseb(b, n - t, a)) 
					palindromes[i--] = n - t;
			}
			else
			{
				reached_zero = true;
				k = 0;
				i++;
				while (i != j)
				{
					palindromes[k++] = palindromes[i];
					i++;
				}
				j = k;
				i = -1;
			}
		}
		if (j < 5 && convertToBaseb(b, n + t, a))
		{
			enteredAtY = true;
			palindromes[j++] = n + t;
		}
		if ((i < 0 && j < 5) && convertToBaseb(b, n - t, a) && !enteredAtX && !reached_zero)
		{
			rotate(palindromes,j,1);
			palindromes[0] = n - t;
			j++;

		}
		if ((i > -1 && j > 4) && convertToBaseb(b, n + t, a) && !enteredAtY)
		{
			rotate(palindromes, i, 0);
			palindromes[4] = n + t;
			i--;
		}
	}
}
	