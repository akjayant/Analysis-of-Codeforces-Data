#include <bits/stdc++.h>
using namespace std;
int n, k;
int input[10000];
int maxsize = 0;
int main()
{
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		maxsize = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &input[i]);
		sort(input, input + n);
		for (int i = 1; i <= n; i++)
		{
			maxsize = max(min(input[n - i], i), maxsize);
		}
		printf("%d\n", maxsize);
	}
}