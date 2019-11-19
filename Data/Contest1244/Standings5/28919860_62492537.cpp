#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <set>
#include <stack>


using namespace std;
using ll = long long;

ll buf = 0;

#define SZ(a) a.size()
#define pb(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define mp(a,b) make_pair(a,b)

vector <ll> color;
vector <vector<int>> gr;
vector <bool> used;
vector <vector<ll>> cost;
int ind = 0;
int par = 0;

bool check = true;

int col(int u)
{
	bool f1=false, f2=false, f3=false;
	for (auto to: gr[u])
	{
		if (color[to] == 1)
		{
			f1 = true;
		}
		if (color[to] == 2)
		{
			f2 = true;
		}
		if (color[to] == 3)
		{
			f3 = true;
		}
		for (auto it : gr[to])
		{
			if (color[it] == 1)
			{
				f1 = true;
			}
			if (color[it] == 2)
			{
				f2 = true;
			}
			if (color[it] == 3)
			{
				f3 = true;
			}
		}
	}
	if (!f3)
	{
		return 3;
	}
	if (!f2)
	{
		return 2;
	}
	return 1;
}

void dfs(int v)
{
	used[v] = true;
	for (auto to : gr[v])
	{
		if ((v == 0 && to == gr[v][0])&&check)
		{
			check = false;
			dfs(to);
		}
		if (!used[to])
		{
			color[to] = col(to);
			buf += cost[to][color[to]-1];
			dfs(to);
		}
	}
}

int main() {
	//ifstream cin("input.txt");
	int n;
	cin >> n;
	gr.assign(n, vector<int>(0, 0));
	cost.assign(n, vector<ll>(3, 0));
	used.assign(n, false);
	color.assign(n, 0);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[j][i];
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		gr[u].pb(v);
		gr[v].pb(u);
		if (gr[u].size() > 2 || gr[v].size() > 2)
		{
			cout << -1;
			return 0;
		}
	}
	ll cos = 1e15;
	int v = 0;
	vector <int> ans(n);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i!=j)
			{
			check = true;
			color.assign(n, 0);
			used.assign(n, false);
			used[v] = true;
			color[v] = i+1;
			color[gr[v][0]] = j+1;
			buf = 0;
			ind = gr[v][0];


				buf += cost[v][i];
				buf += cost[gr[v][0]][j];
				//cout << buf << " ";
				dfs(v);
				//cout << buf << '\n';
				if (buf < cos)
				{
					cos = min(cos, buf);
					for (int i = 0; i < n; i++)
					{
						ans[i] = color[i];
					}
				}
			}
		}
	}
	cout << cos << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";

	}
	return 0;
}