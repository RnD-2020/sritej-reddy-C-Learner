//
// Every number repeats twice, except one number.
// Write a function that finds the number that does not repeat.
//
// e.g:
// {11, 8, 11}, 3  => 8
//
int numberWithoutRepeatition(int numbers[], int size) {
	int i, j;
	//in thins i am replacing every repeated number with "numbers[0]" 
	if (size == 1)
		return numbers[0];
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (i != 0 && numbers[i] == numbers[0])
				break;
			if ((i == 0 || numbers[i] != numbers[0]) && numbers[i] == numbers[j])
			{
				numbers[i] = numbers[0];
				numbers[j] = numbers[0];
				break;
			}
		}
		if (j == size)
			return numbers[i];
	}
}

//
// encode an array of numbers by doing
// XOR with n'th prime number
// and subtract 1
//
// output the encode numbers in encodedMessage[8] array.
//
// e.g:
// for 5'th prime
// encoding will be
// (message[i] ^ 11) - 1
// since 11 is the 5'th prime. // 2, 3, 5, 7, 11...
//
bool isPrime(int n)
{
	if (n % 3 == 0 || n % 5 == 0)
		return false;
	for (int i = 6; i <= n / 2 + 1; i++)
		if (n%i == 0)
			return false;
	return true;
}
void encodeWithNthPrime(int message[8], int n, int encodedMessage[8]) {
	int prime_num;
	if (n <=2)
		prime_num = n+1;
	else prime_num = 5;
	while (n-3)
	{
		if (prime_num%2!=0 && isPrime(prime_num))
			n--;
		prime_num++;
	}
	prime_num--;
	for (int i = 0; i < 8; i++)
	{
		encodedMessage[i] = (message[i] ^ prime_num) - 1;
	}
}

//
// decode an array of numbers in
// which are encoded using above encodeWithPrime function.
//
// output the decoded numbers in decodedMessage[8] array.
//
void decodeWithNthPrime(int message[8], int n, int decodedMessage[8]) {
	int prime_num;
	if (n <= 2)
		prime_num = n + 1;
	else prime_num = 5;
	while (n - 3)
	{
		if (prime_num % 2 != 0 && isPrime(prime_num))
			n--;
		prime_num++;
	}
	prime_num--;
	for (int i = 0; i < 8; i++)
	{
		decodedMessage[i] = ((message[i] + 1) ^ prime_num);
	}
}

//
// Encode data and flags in packet header
//
// From Left to Right the data and flags are packed as follows:
// fromMobileId   - 7 bits
// toMobileId     - 7 bits
// msgId          - 7 bits
// msgLen         - 7 bits
// reserved       - 2 bits
// urgent         - 1 flag bit
// adHoc          - 1 flag bit
//
// Note:
// The values will be in the range
// 0 <= fromMobileId, toMobileId, msgId, msgLen <= 127
//
// The reserved bits should be set to zero.
//
// For the context refer:
// https://en.wikipedia.org/wiki/Transmission_Control_Protocol#TCP_segment_structure
//
unsigned int packHeader(int fromMobileId, int toMobileId, int msgId,
                        int msgLen, bool urgent, bool adHoc) {
	unsigned int res = 0;
	res = res | fromMobileId;
	res = res << 7;
	res = res | toMobileId;
	res=res << 7;
	res = res | msgId;
	res=res << 7;
	res = res | msgLen;
	res=res << 3;
	if (urgent)
		res = res | 1;
	else res = res | 0;
	res=res << 1;
	if (adHoc)
		res = res | 1;
	else
		res = res | 0;

    return res;
}

// unpack a given header, with the properties like the above
void unpackHeader(unsigned int header, int *pFromMobileId, int *pToMobileId,
                  int *pMsgId, int *pMsgLen, bool *pUrgent, bool *pAdHoc) {

	unsigned int temp = header;
	int number;

	temp >>= 1;
	temp <<= 1;
	number = header^temp;
	if (number)
		*pAdHoc = true;
	else *pAdHoc = false;

	temp >>= 2;
	temp <<= 1;
	header >>= 1;
	number = header^temp;
	if (number)
		*pUrgent = true;
	else *pUrgent = false;

	temp >>= 10;
	temp <<= 7;
	header >>= 3;
	*pMsgLen = header^temp;

	temp >>= 14;
	temp <<= 7;
	header >>= 7;
	*pMsgId = header^temp;

	temp >>= 14;
	temp <<= 7;
	header >>= 7;
	*pToMobileId = header^temp;

	temp >>= 14;
	temp <<= 7;
	header >>= 7;
	*pFromMobileId = header^temp;
}
