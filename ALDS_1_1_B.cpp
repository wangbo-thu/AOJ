// ALDS_1_1_B.cpp
// Greatest Common Divisor

#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b); // if a < b, then a % b = a;
}

int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);
	int c = gcd(a, b);
	printf("%d\n", c);
	return 0;
}