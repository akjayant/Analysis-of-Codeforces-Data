#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<map>
#include<bitset>
#include<unordered_map>
#include<cstring>
#include<cctype>
using namespace std;
#define  ll long long
#define  ull unsigned long long
#define  ul unsigned long
#define all(v) v.begin(),v.end()
#define sz(n) (int)n.size()
#define pb(s) push_back(s);
#define format(n) fixed<<setprecision(n)
#define finl "\n"
#define Mohammed_Atef_Hassan fast();
#define mod 1000000007
#define INF LLONG_MAX
#define PI acos(-1)
#define clr(dp,n) memset(dp,n,sizeof dp)
#define ex(n) return cout<<n<<finl,0;
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll fix_mod(ll x, ll y)
{
	return (y + x % y) % y;
}
void fast() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

#ifdef ONLINE_JUDGE
	//freopen("crosses.in", "r", stdin);

	//freopen("crosses.out", "w", stdout);
#endif
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}
int main()
{
	Mohammed_Atef_Hassan
		int n, m;
	cin >> n >> m;
	vector<set<int>>edg(n + 1);
	int u, v;
	while (m--)
	{
		cin >> u >> v;
		edg[u].insert(v);
		edg[v].insert(u);
	}
	set<int>s;
	for (int i =1; i <= n; i++)
	{
		s.insert(i);
	}
	queue<int>q; int cnt = n;
	while (!s.empty())
	{
		q.push(*s.begin()); s.erase(*s.begin());
		while (!q.empty())
		{
			int p = q.front(); q.pop();
			vector<int>bb;
			for (auto c : s)
			{
				if (edg[p].find(c) == edg[p].end())
				{
					bb.push_back(c);
					q.push(c);
					cnt--;
				}
			}
			for (auto c : bb)
				s.erase(c);
		}
	}
	cout << cnt-1<< finl;
}