/*
level: Hard

1. Try all possible fibonacci generation approaches to solve this problem
2. Do research on fibonacci sequence and come up with suitable solution to solve this problem
3. Come up with Clean and maintainable code 
4. Discuss your approach and it's time complexity in the forum thread:

Problem statement : Given an integer N return Nth fibonacci mod 10 ^ 9 + 7 (consider fib(3) is 2)
for invalid inputs return -1

P.s: For this problem time complexity plays an important role and
the value of N may vary from:

1 <= N <= 10^8

*/
const int mod = 1000000007;
typedef long long ll;
void multiply(ll a[], ll b[])
{
	int v[4] = { 0 };
	v[0] = (a[0] * b[0] + a[1] * b[2]) % mod;
	v[1] = (a[0] * b[1] + a[1] * b[3]) % mod;
	v[2] = (a[2] * b[0] + a[3] * b[2]) % mod;
	v[3] = (a[2] * b[1] + a[3] * b[3]) % mod;
	a[0] = v[0];
	a[1] = v[1];
	a[2] = v[2];
	a[3] = v[3];
}


void finder(long long x, long long temp[])
{
	if (x == 0 || x == 1)
		return;
	long long a[] = { 1, 1, 1, 0 };
	finder(x / 2, temp);
	multiply(temp, temp);
	if (x % 2 != 0)
		multiply(temp, a);
}
int answering(long long x)
{
	long long v[] = { 1, 1, 1, 0 };
	finder(x, v);
	return int(v[0]);
}
int bigFibonacci(int N){
	if (N <= 0)
		return -1;
	return answering(N - 1);
}
