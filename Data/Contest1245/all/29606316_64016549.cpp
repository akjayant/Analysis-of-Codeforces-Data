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

vector<int> dsu;
vector<int> r;

int par(int v)
{
	return dsu[v] == v ? v : dsu[v] = par(dsu[v]);
}

void unite(int u, int v) // v k u
{
	u = par(u);
	v = par(v);
	dsu[v] = u;
}


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> coord;
	for (int i = 0; i < n; i++)
	{
		dsu.push_back(i);
		int x, y;
		cin >> x >> y;
		coord.push_back({ x, y });
	}
	vector<long long> c, k;
	r.assign(n, 0);
	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		long long v;
		cin >> v;
		c.push_back(v);
		ans += v;
	}

	for (int i = 0; i < n; i++)
	{
		long long v;
		cin >> v;
		k.push_back(v);
	}
	vector<pair<long long, pair<int, int>>> g;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			g.push_back({ (long long(abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second))) * (k[i] + k[j]), {i, j} });
		}
	}
	sort(g.begin(), g.end());
	vector<pair<int, int>> e;
	for (int i = 0; i < g.size(); i++)
	{
		int u = g[i].second.first;
		int v = g[i].second.second;
		int u1 = par(u);
		int v1 = par(v);
		if (u1 != v1)
		{	

			long long mxv = max(c[u1], c[v1]);
			if (mxv > g[i].first)
			{
				ans -= mxv;
				ans += g[i].first;
				e.push_back({u, v});
				if (c[u1] > c[v1])
				{
					unite(v, u);
				}
				else
				{
					unite(u, v);
				}
			}
		}
	}
	cout << ans << "\n";
	int cnt = 0, cnt1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (dsu[i] == i) cnt++;
	}
	cout << cnt << "\n";
	for (int i = 0; i < n; i++)
	{
		if (dsu[i] == i)
		{
			cout << i + 1 << " ";
		}
	}
	cout << "\n" << e.size() << "\n";
	for (int i = 0; i < e.size(); i++)
	{
		cout << e[i].first + 1 << " " << e[i].second + 1 << "\n";
	}
	gg;
}