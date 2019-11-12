#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

const int MAX_N = 1e2 + 5;

int q, a, b, c, f[MAX_N][MAX_N][MAX_N];

int solve(int a, int b, int c)
{
	if (f[a][b][c] != -1)
		return f[a][b][c];
	f[a][b][c] = 0;
	if (b >= 1 && c >= 2)
		f[a][b][c] = std::max(f[a][b][c], solve(a, b - 1, c - 2) + 3);
	if (a >= 1 && b >= 2)
		f[a][b][c] = std::max(f[a][b][c], solve(a - 1, b - 2, c) + 3);
	return f[a][b][c];
}

int main()
{
	memset(f, 0xff, sizeof(f));
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", solve(a, b, c));
	}
	return 0;
}
