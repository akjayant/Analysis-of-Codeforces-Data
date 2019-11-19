#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<vector<int>> c;
vector<int> color;

ll getCost(int u, const vector<int>& mask, const vector<vector<int>>& g, int prev, int cnt)
{
	for (auto v : g[u])
	{
		if (v != prev)
			return getCost(v, mask, g, u, cnt + 1) + c[mask[cnt % 3]][u];
	}
	return c[mask[cnt % 3]][u];
}

void setColor(int u, const vector<int>& mask, const vector<vector<int>>& g, int prev, int cnt)
{
	color[u] = mask[cnt % 3] + 1;
	for (auto v : g[u])
	{
		if (v != prev)
		{
			setColor(v, mask, g, u, cnt + 1);
			return;
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;

	c.resize(3, vector<int>(n));
	color.resize(n);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j)
			cin >> c[i][j];

	vector<vector<int>> g(n);
	int f, s;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> f >> s;
		g[--f].push_back(--s);
		g[s].push_back(f);
	}

	int m = 0;
	bool ok = true;
	for (int i = 0; i < n; ++i)
	{
		if (g[i].size() > 2)
			ok = false;
		if (g[i].size() == 1)
			m = i;
	}

	if (!ok)
	{
		cout << -1 << endl;
		return 0;
	}

	vector<vector<int>> masks = { {0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1} };
	vector<ll> costs(masks.size(), 0);
	ll minC = 0;
	for (int i = 0; i < masks.size(); ++i)
	{
		costs[i] = getCost(m, masks[i], g, -1, 0);
		if (costs[i] < costs[minC])
			minC = i;
	}

	setColor(m, masks[minC], g, -1, 0);
	cout << costs[minC] << endl;
	for (auto x : color)
		cout << x << " ";

	return 0;
}