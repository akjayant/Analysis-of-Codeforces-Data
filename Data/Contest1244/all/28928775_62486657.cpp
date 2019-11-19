#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;
vector<int> c[3];
long long n;
vector<set<int>> u;
vector<int> GetC(int num, int c1, int c2)
{
	vector<int> g(n, 0);
	g[num] = c1;
	int z = *u[num].begin(), cp, cpp;
	g[z] = c2;
	cp = c2;
	cpp = c1;
	queue<pair<int, pair<int, int>>> q;
	q.push({ z, {cp, cpp} });
	while (q.size())
	{
		pair<int, pair<int, int>> h = q.front();
		z = h.first;
		cp = h.second.first;
		cpp = h.second.second;
		q.pop();
		int kk = 0;
		for (auto k : u[z])
		{	
			if (g[k] == 0)
			{
				g[k] = (6 - cpp - cp);
				q.push({ k, {6 - cpp - cp, cp} });
				kk++;
			}
		}
		if (kk > 1)
		{
			vector<int> q = { -1 };
			return q;
		}
	}
	return g;
}
long long getS(int num, int c1, int c2)
{
	vector<int> g = GetC(num, c1, c2);
	if (g[0] == -1)
		return -1;
	long long s = 0;
	for (int i = 0; i < n; i++)
		s += c[g[i] - 1][i];
	return s;
}
int  main()
{
	cin >> n;

	for (int i = 0; i < 3; i++)
	{
		c[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> c[i][j];
	}
	long long a, b;
	u.resize(n);
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		a--, b--;
		u[a].insert(b);
		u[b].insert(a);
	}
	int mn = n;
	for(int i = 0; i < n; i++)
		if (u[i].size() == 1)
		{
			mn = i;
		}
	long long mmn = -1, mmi = 0, mmj = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			if (i != j)
			{
				long long s;
				s = getS(mn, i, j);
				if (s < mmn || mmn == -1)
					mmn = s, mmi = i, mmj = j;
			}
	vector<int> bb = GetC(mn, mmi, mmj);
	if (mmn == -1)
	{
		cout << -1;
		return 0;
	}
	cout << mmn << endl;
	for (int i = 0; i < n; i++)
		cout << bb[i] << ' ';
	return 0;
}