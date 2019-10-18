//
//  E02_Bitwise.cpp
//  Unit1_exercise2_understanding_bitwise
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E02_BitwiseSpec.cpp file.
 
 Your primary goal is to implement all these functions by using
 bitwise operators only.
 
 */

int andOfEachByte(int n) {
	
    return (n&255) & (n>>8 & 255) & (n>>16 & 255) & (n>>24 & 255);
}

//
// Note1:
// implement the function using bitwise operators only
// should not use * and + operators.
int numberFromBits(int bits[32]) {
	int res=0;
	for (int i = 0; i < 32; i ++)
	{
		res = res | (bits[i] << (31 - i));
	}

    return res;
}

//
// Note2:
// implement the function using bitwise operators only
// should not use % and / operators.
void bitsFromNumber(int n, int bits[32]) {
	int count=0;
	while (count < 32)
	{
		bits[31-(count++)] = n & 1;
		n = n >> 1;
	}
}

//
// Note3:
// Refer this to understand how numbers are represented in binary format
// https://www.youtube.com/watch?v=qrUjFtZZWf4
// mainly how negative number are represented.
//
// implement this function by calling above bitsFromNumber function only.
//
int numberOfOnesInBinary(int n) {
	if (n)
	{
		if (n < 0)
		{
			n = n & 0x7fffffff;
			return 1 + numberOfOnesInBinary(n);
		}
		else if ((n & 1) == 1)
		{
			return 1 + numberOfOnesInBinary(n >> 1);
		}
		else
		{
			return numberOfOnesInBinary(n >> 1);
		}
	}
	return 0;
}

//
// Returns
//  1 - yes
//  0 - no
//
int isPalindromeInBase256(unsigned long int n) {
	int byte1 = n & 255, byte2 = n >> 8 & 255, byte3 = n >> 16 & 255, byte4 = n >> 24 & 255;
	if (byte2==0 && byte3 ==0 && byte4==0)
	{
		return 1;
	}
	if (byte3==0 && byte4==0)
	{
		if (((byte1 << 8 ) | (byte2 )) == n)
			return 1;
		return 0;
	}
	if (byte4 == 0)
	{
		if (((byte1 << 16 ) | (byte2<<8) | (byte3)) == n)
		{
			return 1;
		}
		return 0;
	}
	return (((byte1 << 24) | (byte2 << 16) | (byte3 << 8) | (byte4)) == n ? 1 : 0);
}
