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

ll n, k, a[200005], minelem, maxelem;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	a[n] = 100 * mod;
	fr(i, n)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	maxelem = n - 1;
	while (a[minelem + 1] == a[minelem])
		minelem++;
	while (a[maxelem - 1] == a[maxelem])
		maxelem--;
	while (k >= 0)
	{
		if (a[minelem] == a[maxelem])
		{
			cout << 0 << endl;
			return 0;
		}
		if (minelem < n - 1 - maxelem)
		{
			if ((minelem + 1)*(a[minelem + 1] - a[minelem]) <= k)
			{
				k -= (minelem + 1)*(a[minelem + 1] - a[minelem]);
				minelem++;

				while (a[minelem + 1] == a[minelem])
					minelem++;
			}
			else
			{
				ll t = k / (minelem + 1);
				cout << a[maxelem] - a[minelem] - t << endl;
				return 0;
			}
		}
		else
		{
			if ((n-maxelem)*(a[maxelem] - a[maxelem-1]) <= k)
			{
				k -= (n - maxelem)*(a[maxelem] - a[maxelem - 1]);
				maxelem--;

				while (a[maxelem - 1] == a[maxelem])
					maxelem--;
			}
			else
			{
				ll t = k / (n-maxelem);
				cout << a[maxelem] - a[minelem] - t << endl; return 0;
			}
		}
	}


	
	return 0;
}
//mipt-atp-distrib209
//ZhpJAP1KRsZ