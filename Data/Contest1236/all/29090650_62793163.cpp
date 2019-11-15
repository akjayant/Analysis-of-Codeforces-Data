#include <bits/stdc++.h>

using namespace std;
int n, ans[301][301];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 1; j <= n; ++j)
			ans[(i % 2) ? j : n - j + 1][i + 1] = i * n + j;
	for(int i = 1; i <= n; ++i, printf("\n"))
		for(int j = 1; j <= n; ++j)
			printf("%d ", ans[i][j]);
}