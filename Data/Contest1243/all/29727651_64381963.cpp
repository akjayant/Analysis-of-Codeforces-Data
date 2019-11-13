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
int c1[26], c2[26];
int main()
{
	Mohammed_Atef_Hassan
		int k, n; string s, t;
	cin >> k;
	while (k--)
	{
		clr(c1, 0); clr(c2, 0);
		cin >> n;
		cin >> s >> t;
		int cnt = 0; vector<int>v;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != t[i])cnt++, v.push_back(i);
		}
		if (cnt > 2)cout << "No" << finl;
		else
		{
			swap(s[v[0]], t[v[0]]);
			if (s == t)cout << "Yes" << finl;
			else
			{
				swap(s[v[0]], t[v[0]]);
				if (v.size() == 2)
				{
					swap(s[v[0]], t[v[1]]);
					if (s == t)cout << "Yes" << finl;
					else
					{
						swap(s[v[0]], t[v[1]]);
						swap(s[v[1]], t[v[0]]);
						if (s == t)cout << "Yes" << finl;
						else
						{
							swap(s[v[1]], t[v[0]]);
							swap(s[v[1]], t[v[1]]);
							if (s == t)cout << "Yes" << finl;
							else cout << "No" << finl;
						}
					}
				}
				else cout << "No" << finl;
			}
		}
	}
}