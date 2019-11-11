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


void solve()
{
	ll a, b, c, i, n, j, x=0, y=0, z=0, sum = 0;
	string s;

	cin >> n;
	cin >> a >> b >> c >> s;

	for (auto it : s)
	{
		if (it == 'R')
		{
			x++;
		}
		else if (it == 'P')
		{
			y++;
		}
		else
		{
			z++;
		}
	}

	swap(a, x);
	swap(b, y);
	swap(c, z);

	string res = s;

	for (auto& it : res)
	{
		it = '*';
	}

	for (i = 0; i < n; i++)
	{
		if (s[i] == 'R' && y>0)
		{
			sum++;
			res[i] = 'P';
			y--;
		}
		else if (s[i] == 'P' && z>0)
		{
			sum++;
			res[i] = 'S';
			z--;
		}
		else if (s[i] == 'S' && x > 0)
		{
			sum++;
			res[i] = 'R';
			x--;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (res[i] == '*')
		{
			if (x>0)
			{
				x--;
				res[i] = 'R';
			}
			else if (y > 0)
			{
				y--;
				res[i] = 'P';
			}
			else
			{
				z--;
				res[i] = 'S';
			}
		}
	}

	if (sum * 2 >= n)
	{
		cout << "YES\n";
		cout << res << "\n";
	}
	else
	{
		cout << "NO\n";
	}
}


int main()
{
	fast;

	int t, tt;

	cin >> t;

	for (tt = 0; tt < t; tt++)
	{
		solve();
	}


	return 0;
}