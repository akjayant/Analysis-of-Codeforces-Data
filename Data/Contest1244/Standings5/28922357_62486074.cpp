#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

#include <functional>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cassert>

#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>

#include <string>
#include <iterator>
#include <iomanip>
#include <fstream>

using namespace std;

#define uint unsigned int
#define prll pair<ll,ll>
#define prdd pair<double,double>
#define m_p make_pair
#define ticonst (ll)1337228
#define INF (ll)1e18
#define ll long long

const ll q = 239017;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 13;
const ll MAXN = 1e5 + 100;
const ll MAXM = 310;
const ll L = 26;

set<ll> g[MAXN];
ll col[3][MAXN];

ll rs[MAXN];

vector<ll> order;
void dfs(ll v, ll p)
{
	order.push_back(v);
	for (ll to : g[v])
	{
		if (to == p)
			continue;
		dfs(to, v);
	}
}

void $main()
{
	ll n; cin >> n;

	for (ll i = 0; i < 3; ++i)
		for (ll j = 0; j < n; ++j)
			cin >> col[i][j];

	for (ll i = 0; i < n-1; ++i)
	{
		ll u, v; cin >> u >> v;
		--u; --v;

		g[u].insert(v);
		g[v].insert(u);
	}


	ll one=0,two = 0;
	for (ll i = 0; i < n; ++i)
	{
		one += ((ll)g[i].size()) == 1;
		two += ((ll)g[i].size()) == 2;
	}

	if (!(one == 2 && two == n - 2))
	{
		cout << -1;
		exit(0);
	}

	for (ll i = 0; i < n; ++i)
	{
		if ((ll)g[i].size() == 1)
		{
			dfs(i,i);
			break;
		}
	}

	vector<ll> v = { 0,1,2 };

	ll ans = INF;
	do
	{
		ll meg = 0;
		for (ll i = 0; i < n; ++i)
			meg += col[v[i % 3]][order[i]];

		if (meg < ans)
		{
			ans = meg;
			for (ll i = 0; i < n; ++i)
				rs[order[i]] = v[i % 3];
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << '\n';
	for (ll i = 0; i < n; ++i)
		cout << rs[i]+1 << " ";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#else
	//freopen("wizard.in", "r", stdin);
	//freopen("wizard.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// 🍑🍑🍑 //

	$main();

	return 0;
}

//257593BA