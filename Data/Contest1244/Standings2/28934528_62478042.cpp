#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <string>
#include <memory.h>
#include <bitset>
#include <stack>
#include <assert.h>
using namespace std;
#define ll  long long
#define ld long double
#define ppi pair<int, int>
#define mp make_pair	
const int N = 2e5 + 111 , NS = 1e6 + 11;
int cost[N][3], freq[N];
vector<int> graph[N];
vector<int> seq;
void dfs(int u, int p)
{
	seq.push_back(u);
	for (auto v : graph[u])
		if (v != p)
			dfs(v, u);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
	int n; cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &cost[j][i]);
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0; i < n; i++)
		if (graph[i].size() >= 3)
			return puts("-1"), 0;
	for (int i=0 ; i < n ; i++)
		if (graph[i].size() == 1)
		{
			dfs(i, -1);
			break;
		}
	assert(seq.size() == n);
	int per[3]{ 0 , 1 , 2 };
	ll ans = 1e18;
	do
	{
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			int p = per[i % 3];
			sum += cost[seq[i]][p];
		}
		if (sum < ans)
		{
			for (int i = 0; i < n; i++)
			{
				int p = per[i % 3];
				freq[seq[i]] = p + 1;
			}
			ans = sum;
		}
	} while (next_permutation(per, per + 3));
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		printf("%d ", freq[i]);
}