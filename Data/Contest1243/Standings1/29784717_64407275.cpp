#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include <queue>
#include <string>
#include <set>

typedef  long long lol;
using namespace std;

#define fori(i,j,k) for (int (i)=(j);(i) < (k);(i)++)
#define MOD 4294967296ULL
#define EPS 0.000000001

set<int> edg[101000];

int main() {

#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		edg[a].insert(b);
		edg[b].insert(a);
	}

	vector<bool> taken(n, false);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (taken[i])
			continue;

		cnt++;
		set<int> curr = edg[i];
		taken[i] = true;
		queue<int> to_process;
		for (int k = 0; k < n; k++)
		{
			if (curr.find(k) == curr.end())
			{
				taken[k] = true;
				to_process.push(k);
			}
		}

		while (to_process.size() > 0)
		{
			int j = to_process.front();
			to_process.pop();

			vector<int> to_drop;
			for (int x : curr)
			{
				if (edg[j].find(x) == edg[j].end())
				{
					to_drop.push_back(x);
					taken[x] = true;
					to_process.push(x);
				}
			}

			for (int x : to_drop)
				curr.erase(x);
		}
	}

	cout << cnt - 1;

	return 0;
}