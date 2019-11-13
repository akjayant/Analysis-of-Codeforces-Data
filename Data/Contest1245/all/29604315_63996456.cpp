#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<assert.h>
#include<functional>
using namespace std;

#define INF 1234567890
#define ll long long

int T, N;

int Gcd(int a, int b)
{
	return a ? Gcd(b%a, a) : b;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		if (Gcd(A, B) != 1) printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}