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

ll t, a, b, c;

ll binpow(ll x,ll a)
{
	if (a == 1)
	{
		return x;
	}
	if (a % 2 == 1)
		return (x*binpow((x*x) % mod, (a - 1) / 2)) % mod;
	else
		return (binpow((x*x) % mod, a / 2)) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		ll ans = 0;
		ans += min(b, c / 2);
		b -= ans;
		ans *= 3;
		ans += (3*min(a, b / 2));
		cout << ans << endl;
	}
	return 0;
}