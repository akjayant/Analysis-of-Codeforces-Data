#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <time.h>
#include <random>
#include <memory.h>
#include <bitset>
using namespace std;

#define FILE0
#define MAGIC0
mt19937 rnd(time(0)); //rnd()

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define msl map<string, ll>
#define mls map<ll, string>
#define MOD (1000000007ll)
#define MOD2 (1000000009ll)
#define BIGMOD (1000000000000000007ll)
#define RMOD int(5e8 + rnd() % (int) 5e8)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef FILE1
ifstream in("input.txt");
ofstream out("output.txt");
#endif
#ifdef MAGIC1
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#endif

bool isPrime(ll a)
{
	ll i;
	for (i = 2; i*i <= a; i++)
	{
		if (a%i == 0)
		{
			return 0;
		}
	}
	return (a != 1);
}

bool isPalindrom(const string &s, int l, int r)
{
	for (int i = 0; i < (r - l + 1) / 2; i++)
	{
		if (s[l + i] != s[r - i])
		{
			return 0;
		}
	}
	return 1;
}

template <class type1> type1 gcd(type1 a, type1 b)
{
	type1 t;
	while (b)
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

ll positiveMod(ll v, ll md)
{
	v = v%md;
	if (v < 0)
	{
		v += md;
	}
	return v;
}

//-----------------------------------------------------end--------------------------------------//

ll dp[2005][2];
pll cord[2005];
ll c[2005];
ll k[2005];

ll mat[2005][2005];

vector <pll> ed;
vector <pll> rr;
vector <ll> ned;

ll inf[2005];
ll infV[2005];

int main()
{
	fast;

	ll n, i, j, a, b, res = 0;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> cord[i].first >> cord[i].second;
	}
	for (i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (i = 1; i <= n; i++)
	{
		cin >> k[i];
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				mat[i][j] = BIGMOD;
			}
			else
			{
				mat[i][j] = mat[j][i] = (k[i] + k[j])*(abs(cord[i].first - cord[j].first) + abs(cord[i].second - cord[j].second));
			}
		}
	}

	mat[n + 1][n + 1] = BIGMOD;
	for (i = 1; i <= n; i++)
	{
		mat[n + 1][i] = mat[i][n + 1] = c[i];
	}

	n++;

	for (int i = 1; i <= n; i++)
	{
		inf[i] = mat[1][i];
		infV[i] = 1;
	}
	for (i = 2; i <= n; i++)
	{
		ll pos = 1, val = BIGMOD;
		for (j = 1; j <= n; j++)
		{
			if (inf[j] < val)
			{
				pos = j;
				val = inf[j];
			}
		}

		res += val;
		rr.push_back({ infV[pos], pos });

		inf[pos] = BIGMOD;
		for (j = 1; j <= n; j++)
		{
			if (inf[j] != BIGMOD)
			{
				if (inf[j] > mat[pos][j])
				{
					inf[j] = mat[pos][j];
					infV[j] = pos;
				}
			}
		}
	}

	for (auto it : rr)
	{
		if (it.first == n || it.second == n)
		{
			ned.push_back(min(it.first, it.second));
		}
		else
		{
			ed.push_back(it);
		}
	}


	cout << res << "\n";
	cout << ned.size() << "\n";
	for (auto it : ned)
	{
		cout << it << " ";
	}
	cout << "\n";
	cout << ed.size() << "\n";
	for (auto it : ed)
	{
		cout << it.first << " " << it.second << "\n";
	}

	return 0;
}