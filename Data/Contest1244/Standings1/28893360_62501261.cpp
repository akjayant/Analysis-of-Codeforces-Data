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

ll n, x, y, max1, max2, t;
vector<ll> b[100005];
char c[10000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> c;
		max1 = 0;
		max2 = 0;
		fr(i, n)
		{
			if (c[i] == '1')
			{
				max1 = 2 * (n - i);
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (c[i] == '1')
			{
				max2 = 2 * (i + 1);
				break;
			}
		}
		if (max1 == 0 && max2 == 0)
		{
			max1 = n;
		}
		cout << max(max1, max2) << endl;;
	}
	return 0;
}
//mipt-atp-distrib209
//ZhpJAP1KRsZ