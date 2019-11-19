#include <cstdio>
#include <vector>
#include <cstring>

const int MAX_N = 1e5 + 5;
const int UTIL = 0 ^ 1 ^ 2;

int n, c[MAX_N][3], col[MAX_N];
long long f[MAX_N][3][3];
std::vector<int> adj[MAX_N], p;

void init(int cur, int par)
{
	p.push_back(cur);
	for (int tar : adj[cur])
		if (tar != par)
			init(tar, cur);
}

int main()
{
	scanf("%d", &n);
	for (int k = 0; k < 3; ++k)
		for (int i = 1; i <= n; ++i)
			scanf("%d", &c[i][k]);
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		if (adj[i].size() > 2)
		{
			printf("-1\n");
			return 0;
		}
	p.reserve(n);
	for (int i = 1; i <= n; ++i)
		if (adj[i].size() == 1)
		{
			init(i, 0);
			break;
		}
	memset(f, 0x0f, sizeof(f));
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (i != j)
				f[2][i][j] = c[p[1]][i] + c[p[0]][j];
	for (int i = 3; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				if (j != k)
				{
					f[i][j][k] = std::min(f[i][j][k], f[i - 1][k][UTIL ^ j ^ k] + c[p[i - 1]][j]);
					//printf("f %d %d %d -> %lld\n", i, j + 1, k + 1, f[i][j][k]);
				}
	long long ans = 1e18;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			ans = std::min(ans, f[n][i][j]);
	printf("%lld\n", ans);
	int k = n;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (f[n][i][j] == ans)
			{
				while (k > 0)
				{
					col[p[k - 1]] = i;
					int tmp = UTIL ^ i ^ j;
					i = j; j = tmp;
					--k;
				}
				break;
			}
	for (int i = 1; i <= n; ++i)
		printf("%d ", col[i] + 1);
	printf("\n");
	return 0;
}
