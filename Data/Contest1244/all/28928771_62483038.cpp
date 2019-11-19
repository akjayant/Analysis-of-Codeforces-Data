#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Edge {
	int to, next;
}es[200010];
int te = 0, first[100010];

void addE(int a, int b)
{
	te++;
	es[te].to = b;
	es[te].next = first[a];
	first[a] = te;
}

int n;
int cost[3][100010], deg[100010];
int col[3][3][100010];

ll dfs(int p, int fa, int pre2, int pre1, int col1, int col2)
{
	int to = -1;
	for (int e = first[p]; e; e = es[e].next)
	{
		to = es[e].to;
		if (to == fa)
		{
			to = -1;
			continue;
		}
		else break;
	}
	col[col1][col2][p] = 3 - pre1 - pre2;
	if (to == -1) return cost[col[col1][col2][p]][p];
	ll ret = dfs(to, p, pre1, col[col1][col2][p], col1, col2) + cost[col[col1][col2][p]][p];
	return ret;
}

ll ans;
int ansi, ansj;

void getdp(int s)
{
	int s2 = -1;
	for (int e = first[s]; e; e = es[e].next)
	{
		s2 = es[e].to;
		break;
	}
	int s3 = -1;
	for (int e = first[s2]; e; e = es[e].next)
	{
		s3 = es[e].to;
		if (s3 == s) continue;
		else break;
	}
	ans = 1e18;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == j) continue;
			col[i][j][s] = i, col[i][j][s2] = j;
			ll tmp = dfs(s3, s2, i, j, i, j);
			if (ans > tmp + cost[i][s] + cost[j][s2])
			{
				ansi = i, ansj = j;
				ans = tmp + cost[i][s] + cost[j][s2];
			}
		}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		cout << col[ansi][ansj][i] + 1 << ' ';
	cout << endl;
	exit(0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int c = 0; c < 3; c++)
		for (int i = 1; i <= n; i++)
			cin >> cost[c][i];
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		addE(a, b); addE(b, a);
		deg[a]++, deg[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (deg[i] >= 3)
		{
			cout << -1 << endl;
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (deg[i] == 1)
			getdp(i);
	return 0;
}
