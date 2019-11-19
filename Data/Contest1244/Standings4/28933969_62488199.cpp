#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <time.h>
//#include <math.h>
#include <cmath>
#include <fstream>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <bitset>
#pragma comment(linker, "/STACK:36777216")
using namespace std;

#define flu fflush(stdout)
#define gg return 0
#define mp make_pair

long long mod = /*27449*//*998244353*/ 1e9 + 7 /*1e9 + 9*/;
long long inf = 1e9;
long double eps = 1e-7;
long double pi = acosl(-1);
ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int>> g;

vector<vector<long long>> a;

vector<int> col;

long long dfs(int v, int c1, int c2, int p)
{
	int v1 = -1;
	for (int i = 0; i < 3; i++)
	{
		if (i != c1 && i != c2)
		{
			v1 = i;
			break;
		}
	}
	long long ans = a[v][c2];
	for (auto to : g[v])
	{
		if (to == p) continue;
		ans += dfs(to, c2, v1, v);
	}
	return ans;
}

void dfs2(int v, int p, int c1, int c2)
{
	int v1 = 0;
	for (int i = 0; i < 3; i++)
	{
		if (i != c1 && c2 != i)
		{
			v1 = i;
			break;
		}
	}
	col[v] = c2;
	for (int i = 0; i < g[v].size(); i++)
	{
		if (g[v][i] == p) continue;
		dfs2(g[v][i], v, c2, v1);
	}
}

int main()
{
	int n;
	cin >> n;
	col.resize(n);
	g.resize(n);
	a.assign(n, vector<long long>(3));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][1];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][2];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	for (int i = 0; i < n; i++)
	{
		if (g[i].size() > 2)
		{
			cout << -1;
			gg;
		}
	}
	int leaf = -1;
	for (int i = 0; i < n; i++)
	{
		if (g[i].size() == 1)
		{
			leaf = i;
			break;
		}
	}
	int nxt = g[leaf][0];
	long long ans = 1e18;
	int cans = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			long long cur = 0;
			if (i == j) continue;
			cur = dfs(nxt, i, j, leaf) + a[leaf][i];
			if (cur < ans)
			{
				ans = cur;
				cans = i * 10 + j;
			}
		}
	}
	col[leaf] = cans / 10;
	col[nxt] = cans % 10;
	dfs2(nxt, leaf, cans / 10, cans % 10);
	cout << ans << endl;
	for (int i = 0; i < n; i++)
	{
		cout << col[i] + 1 << " ";
	}
	gg;
}