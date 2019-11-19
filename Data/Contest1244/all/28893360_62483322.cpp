#include <iostream>
//#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <cstdint>
#include <unordered_map>
using namespace std;
//ifstream fin("dq.in");
//ofstream fout("dq.out");

#define ll long long
#define ld long double
#define pb push_back
//#define mp make_pair
#define fr(i, n) for(ll i=0;i<(ll)n;i++)
#define frx(i, x, n) for(ll i=(ll)x;i<(ll)n;i++)
#define frb(i, n) for(ll i=(ll)n-1;i>=0;i--)
#define frbx(i, x, n) for(ll i=(ll)n-1;i>=(ll)x;i--)
const int64_t mod = (ll)1e9 + 7;
const int64_t primm = 998244353;

ll n, k, a[200005];
char c[200005];
bool chop;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	cin >> c;
	for (int i = 0; i < n; i++)
		a[i] = -1;
	if (c[0] == c[n - 1])
	{
		a[0] = a[n - 1] = 0;
		chop = true;
	}
	for (int i = 1; i < n; i++)
	{
		if (c[i] == c[i - 1])
		{
			a[i] = a[i - 1] = 0;
			chop = true;
		}
	}
	if (!chop)
	{
		if (k % 2 == 1)
		{
			fr(i, n)
			{
				if (c[i] == 'W')
					c[i] = 'B';
				else
					c[i] = 'W';
			}
		}
		fr(i, n)
		{
			cout << c[i];
		}
		cout << endl;
		return 0;
	}
	ll skizb;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			skizb = i;
			break;
		}
	}
	for (int i = skizb; i < 3 * n; i++)
	{
		if (a[i%n] == -1)
		{
			a[i%n] = a[(i - 1) % n] + 1;
		}
	}
	for (int i = 4 * n - 1; i>=0; i--)
	{
		a[i%n] = min(a[(i + 1) % n] + 1, a[i%n]);
	}
	for (int i = 0; i < n; i++)
	{
		if (min(k, a[i]) % 2 == 1)
		{
			if (c[i] == 'W')
				c[i] = 'B';
			else
				c[i] = 'W';
		}
		cout << c[i];
	}
	cout << endl;



	
	return 0;
}
//mipt-atp-distrib209
//ZhpJAP1KRsZ