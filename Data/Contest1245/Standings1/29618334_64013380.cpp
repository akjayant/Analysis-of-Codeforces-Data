#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

const int MAX_N = 2e3 + 5;

struct data { long long cost; int s, t; };
bool operator < (const data &lhs, const data &rhs) { return lhs.cost > rhs.cost; }

int n, x[MAX_N], y[MAX_N];
bool v[MAX_N];
long long k[MAX_N], cost;

std::priority_queue<data> q;
std::vector<int> src;
std::vector<std::pair<int, int>> adj;

long long dist(int i, int j)
{
	long long manh = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
	return manh * (k[i] + k[j]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", x + i, y + i);
	for (int i = 1; i <= n; ++i)
	{
		int c; scanf("%d", &c);
		q.push({c, i, i});
	}
	for (int i = 1; i <= n; ++i)
		scanf("%lld", k + i);
	while (!q.empty())
	{
		data cur = q.top(); q.pop();
		if (!v[cur.t])
		{
			v[cur.t] = true; cost += cur.cost;
			if (cur.s == cur.t) src.push_back(cur.t);
			else adj.push_back({cur.s, cur.t});
			for (int i = 1; i <= n; ++i)
				if (!v[i]) q.push({dist(cur.t, i), cur.t, i});
		}
	}
	printf("%lld\n%d\n", cost, src.size());
	for (int x : src) printf("%d\n", x);
	printf("%d\n", adj.size());
	for (auto x : adj) printf("%d %d\n", x.first, x.second);
	return 0;
}
