/*Problem - Swapping bits in a given number.

Aim: A positive number is given as input along with two positions p1, p2 and length n. Your job is to write a program that swaps 'n' bits of the number starting from positions p1,p2. p1, p2 are 0-indexed values that start from least significant bit of the number.
	 Use unsigned int data type.

Explanation:
Sample 1: number = 47. Its binary representation is 00101111
          p1 = 1 (Start from 2nd bit from right side)
          p2 = 5 (Start from 6th bit from right side)
          n = 3 (No of bits to be swapped)
          The 3 bits starting from p1 are 00101'111' and the 3 bits staring from p2 are '001'01111. After swapping these two, the resultant binary string will be 1110011
          which is equal to decimal value 227.
          Hence the output must be 227.
          
Sample 2: number = 28. Its binary representation is 11100
          p1 = 0 (Start from 1st bit from right side)
          p2 = 3 (Start from 4th bit from right side)
          n = 2 (No of bits to be swapped)
          The 2 bits starting from p1 are 111'00' and the 2 bits staring from p2 are '11'100. After swapping these two, the resultant binary string will be 00111.
          which is equal to decimal value 7.
          Hence the output must be 7.

Sample 3: number=178. Its binary representation is 10110010.
		  p1=0  (Start from 1st bit from right side)
		  p2=30 (Start from 31st bit from right side)
	      n=5   (No of bits to be swapped)
		  In this case, since range exceeds at position2, use 0's in that case. So, the bits starting from p1 are '10010' and the bits staring from p2 are '00000'.
		  After swapping the two, the resultant binary string will be '10010000000000000000000000010100000'.But considering only 32 bits, dicsard extra bits 
		  on left side and hence resultant string will be '10000000000000000000000010100000' which is equal to decimal value 2147483808
	      Hence the output must be 2147483808.


Constraints:
1) The positions and the length 'n' must always be positive.
2) 0<=p1<p2<=32.
3) If the range overflows 32, discard the extra bits.(See Sample 3)
2) It is guaranteed that positions and ranges will not overlap.
3) It is guaranteed that the number will not exceed 32 bit range. 

Note: If constraints are violated, then return 0.
      Please Use 32 bit data(unsigned int) type to get accurate results.

	  DONT CHANGE THE FUNCTION HEADERS.

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned int swapBits(unsigned int number, int p1, int p2, int n)
{
	if (((p1 < 0 || p2 < 0) || (n < 0)) ||( p2>32) || (p1 + n >= p2))
	{
		return 0;
	}
	if (number == 0)
	{
		return 0;
	}
	unsigned int bin=0,t1,t2,rem;
	int size = 0, power = 1,i=0, count = 0,noofzeros;
	//finding binary equivalent
	while (number >0)
	{
		bin += ((number%2)*power);
		count++;
		/*if (number / 2==0)
		{
			if ((noofzeros = (p2 + n) - count) > 0)
				number = number*(noofzeros * 10);
		}*/
		power *= 10;
		number /= 2;
	}
	int tenpow1=pow(10,p1), tenpow2 = pow(10, p2);
	for (i = 0; i < n; i++)
	{
		if (bin / tenpow1 == 0)
		{
			t1 = 0;
		}
		else {
			t1 = bin / tenpow1;
			t1 = t1 % 10;
		}
		if (bin / tenpow2 == 0)
			t2 = 0;
		else {
			t2 = bin / tenpow2;
			t2 = t2 % 10;
		}


		rem = bin % tenpow1;
		bin = bin / (tenpow1 * 10);
		bin = (bin * 10) + t2;
		bin = (bin*tenpow1) + rem;

		rem = bin % tenpow2;
		bin = bin / (tenpow2 * 10);
		bin = (bin * 10) + t1;
		bin = (bin*tenpow2) + rem;

		tenpow1 *= 10;
		tenpow2 *= 10;
	}






	/*

	if (p2 + n > size)
	{
			size = p2 + n;
	}

	if (noofzeros > 0)
	{
		
	}

	//i am using pointers becoz array[size] is not accepted in vs where size is a variable
	int *ar= (int *)malloc(size * sizeof(int)), temp;
	for(int i=0;i<size;i++)
	{
		if (bin != 0)
		{
			ar[i] = (bin % 10);
			bin /= 10;
		}
		else {
			ar[i] = 0;
		}
	}
	for (p1, p2; n-- != 0; p1++, p2++)
	{
		temp = ar[p1];
		ar[p1] = ar[p2];
		ar[p2] = temp;
	}
	//change till here	
	if (size > 32)
		size = 32;*/
	unsigned int dec_res=0;
	int twopow = 1;
	while(bin)
	{
		dec_res += (bin % 10) * twopow;
		twopow *= 2;

		bin /= 10;
	}
	return dec_res;
}
