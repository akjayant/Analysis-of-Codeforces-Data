#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <stack>
#include <deque>
#include <memory.h>
#include <string>
#include <unordered_map>

#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define vI vector<int>
#define vvI vector<vector<int>>
#define vLL vector<ll>
#define vS vector<string>
#define fori(i, n) for(int (i)=0; (i)<n; (i)++)
#define forn(it,from,to) for(int (it)=from; (it)<to; (it)++)
#define forI(tmp) for(auto(it)=(tmp).begin();(it)!=(tmp).end();(it)++)
#define PI 3.14159265356
#define LD long double
#define sc(a) scanf("%d", &(a))
#define scc(a) scanf("%lld", &(a))
#pragma comment (linker, "/STACK:5000000000")
typedef long long ll;

const ll mod = 1000000007;
ll Inf = (ll)2e9;
ll LINF = (ll)1e18 + 1e17;

using namespace std;

ll binpow(ll x, ll n)
{
	if (n == 0)
		return 1;
	ll res = binpow(x, n / 2);
	res = (res * res) % mod;
	if (n & 1)
		res = (res * x) % mod;
	return res;
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	if (n > m)
		swap(n, m);
	
	vector<ll> f(m + 1);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= m; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= mod;
	}
	ll ans = f[n] + f[m] - 1;
	ans %= mod;
	cout << (2LL * ans) % mod;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}

	return 0;
}
