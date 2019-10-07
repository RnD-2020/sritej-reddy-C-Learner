//
//  E01_Functions.cpp
//  Unit1_exercise1_understanding_functions
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E01_FunctionsSpec.cpp file.
 
 */


//
// Note:
//  Think of all the edge cases.
//
// returns the mid-point of
// given 2 points on X-axis
//
int midPoint(int x1, int x2) {
    return (unsigned)(x1+x2)/2;
}

//
// sum of most significant digits of non-negative integers.
//
int sumOfMSDs(int num1, int num2) {
	int n1=0,n2=0;
	while (num1 && num2 )
	{
		n1 = num1;
		n2 = num2;
		num1 /= 10;
		num2 /= 10;
	}
	//now either num1 will be zero or num2 will be zero so from below two loops either of the one will be running 
	while (num1)
	{
		n1 = num1;
		num1 /= 10;
	}
	while (num2)
	{
		n2 = num2;
		num2 /= 10;
	}
   return n1+n2;
}

//
// sum of two 100 digit positive numbers
//
void sumOf100DigitNumbers(int num1[100], int num2[100], int sum[101]) {
	int i,carry=0,temp;
	for (i = 99; i > -1; i--)
	{
		temp = num1[i] + num2[i] + carry;
		sum[i + 1] = temp % 10;
		carry = temp / 10;
	}
	sum[++i] = carry;
}

//
// product of two 100 digit positive numbers
//
void productOf100DigitNumbers(int num1[100], int num2[100], int prod[200]) {
	int i,j, carry = 0, temp,prod_pos=0,t=199;
	for (i = 0; i < 200; i++)
	{
		prod[i] = 0;
	}
	for (i = 99; i > -1; i--)
	{
		prod_pos = t--;
		carry = 0;
		for (j = 99; j > -1; j--)
		{
			temp = (num2[i] * num1[j]) +prod[prod_pos]+ carry;
			prod[prod_pos--] = temp % 10;
			carry = temp / 10;
		}
		prod[prod_pos] = carry;
	}
	
}
