#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1005
int t, n;
char S[N];
int main()
{
	scanf("%d", &t);
	for (; t--; )
	{
		scanf("%d%s", &n, S + 1);
		int x = 0;
		for (int i = 1; i <= n; i++)
			if (S[i] == '1')
				x = max(x, max(i, n - i + 1));
		printf("%d\n", max(n, 2 * x));
	}
}
