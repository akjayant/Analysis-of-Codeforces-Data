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

ll n, x, y, a[10][100005], top, sum[10], ans[10][100005];
vector<ll> b[100005], t;
bool c[10][100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	t.push_back(0);
	t.push_back(1);
	t.push_back(2);
	cin >> n;
	fr(i, 3)
	{
		frx(j, 1, 1+n)
		{
			cin >> a[i][j];
		}
	}
	fr(i, n - 1)
	{
		cin >> x >> y;
		b[x].push_back(y);
		b[y].push_back(x);
	}
	frx(i, 1, n + 1)
	{
		if (b[i].size() > 2)
		{
			cout << -1 << endl;
			return 0;
		}
		else if (b[i].size() == 1)
			top = i;
	}
	fr(o, 6)
	{
		ll skizb=top;
		fr(i, n)
		{
			sum[o] += a[t[i % 3]][skizb];
			ans[o][skizb] = t[i % 3] + 1;
			c[o][skizb] = true;
			fr(sup, b[skizb].size())
			{
				if (c[o][b[skizb][sup]] == false)
				{
					skizb = b[skizb][sup];
					break;
				}
			}
		}
		next_permutation(t.begin(), t.end());
	}
	ll minn = 10000000*mod, mini;
	fr(i, 6)
	{
		if (sum[i] < minn)
		{
			minn=sum[i];
			mini = i;
		}
	}
	cout << sum[mini] << endl;
	frx(i, 1, n + 1)
	{
		cout << ans[mini][i] << " ";
	}
	cout << endl;
	return 0;
}
//mipt-atp-distrib209
//ZhpJAP1KRsZ