/*
Given an integer as input return it's butterfly number
for example N= 1234
then it's you have to return 12344321 as output
return -1 if it is not possible create a butterfly number for the given input
*/
long long butterFlyNumber(long long N)
{
	/*condition checked in while loop-> for a long long data type max value that can be stored is 18446744073709551615(20 digits)
	so i am checking if result till now has reached till 1000000000000000000(19 digits)
	if yes then if still N has more than 1 digit then we will be returning -1, because
	As there are more than one digits in N adding them to result will definetly cross 20 digits.
	*/
	if (N < 0)
		return -1;
	long long res = N;
	while (N)
	{
		if ((res >= 1000000000000000000 && N / 10 != 0) )
			return -1;
		res = (res * 10) + N % 10;
		N /= 10;
	}
	return res;
}