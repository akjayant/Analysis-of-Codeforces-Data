#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl "\n"
#define int long long

const long INF = 1e8;
const double PI = acos(-1);
int mod = 1e9 + 7;
const int N = 1e5 + 7;

set<int> graph[N];


int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	set<pair<int, int>> s;
	set<int> rem;
	s.insert({0, 1});
	for(int i = 2; i <= n; i++)
	{
		rem.insert(i);
		s.insert({1, i});
	}
	int ans = 0;
	while(!s.empty())
	{
		auto p = *s.begin();
		int u = p.second;
		ans += p.first;
		s.erase(p);
		vector<int> toerase;
		for(auto it = rem.begin(); it != rem.end(); it++)
		{
			int v = *it;
			if(graph[u].find(v) == graph[u].end())
			{
				toerase.pb(v);
				s.erase({1, v});
				s.insert({0, v});
			}
		}
		for(int &val: toerase)
			rem.erase(val);
	}
	cout << ans << endl;
	return 0;
}