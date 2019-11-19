#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <ctime>
#include <utility>
#include <bitset>
#include <random>
#include <iostream>
#include <iterator>
#include <stack>
#include <list>
#include <fstream>

using namespace std;

const long long INF = numeric_limits<long long>::max();
const int MOD = 1000 * 1000 * 1000 + 7;
const int BASE = 257;
const double PI = 2 * acos(0.0);

int other(int c1, int c2)
{
	if (c1 == c2)
		throw 1;
	set<int> s{ 0, 1, 2 };
	s.erase(c1);
	s.erase(c2);
	return *s.begin();
}

long long bfs(const vector<vector<int>>& tree, const vector<vector<int>>& c, vector<int>& ans, int leaf, int nextFromLeaf, int firstC, int secondC)
{
	int n = tree.size();
	long long sum = c[leaf][firstC];
	ans.resize(n);
	queue<pair<int, int>> q;
	q.emplace(leaf, -1);
	ans[leaf] = firstC;
	while (!q.empty())
	{
		auto item = q.front();
		q.pop();
		int v = item.first;
		int parent = item.second;
		for (int adj : tree[v])
		{
			if (adj == parent)
				continue;
			if (adj == nextFromLeaf)
				ans[adj] = secondC;
			else
				ans[adj] = other(ans[v], ans[parent]);
			sum += c[adj][ans[adj]];
			q.emplace(adj, v);
		}
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<vector<int>> c(n, vector<int>(3));
	vector<vector<int>> tree(n);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &c[j][i]);
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	int leaf = -1;
	int nextFromLeaf = -1;
	for (int i = 0; i < n; i++)
	{
		if (tree[i].size() == 1)
		{
			leaf = i;
			nextFromLeaf = tree[i][0];
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (tree[i].size() >= 3)
		{
			printf("-1\n");
			return 0;
		}
	}

	long long sum = numeric_limits<long long>::max();
	vector<int> ans(n), buf(n);
	int firstC = -1, secondC = -1;
	{
		long long t = bfs(tree, c, buf, leaf, nextFromLeaf, 0, 1);
		if (t < sum)
		{
			sum = t;
			ans = buf;
		}
	}
	{
		long long t = bfs(tree, c, buf, leaf, nextFromLeaf, 0, 2);
		if (t < sum)
		{
			sum = t;
			ans = buf;
		}
	}
	{
		long long t = bfs(tree, c, buf, leaf, nextFromLeaf, 1, 0);
		if (t < sum)
		{
			sum = t;
			ans = buf;
		}
	}
	{
		long long t = bfs(tree, c, buf, leaf, nextFromLeaf, 1, 2);
		if (t < sum)
		{
			sum = t;
			ans = buf;
		}
	}
	{
		long long t = bfs(tree, c, buf, leaf, nextFromLeaf, 2, 1);
		if (t < sum)
		{
			sum = t;
			ans = buf;
		}
	} 
	{
		long long t = bfs(tree, c, buf, leaf, nextFromLeaf, 2, 0);
		if (t < sum)
		{
			sum = t;
			ans = buf;
		}
	}

	printf("%I64d\n", sum);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}
