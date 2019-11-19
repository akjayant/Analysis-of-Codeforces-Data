#include <iostream>

using namespace std;
#define var auto
#define ll long long
#define endl '\n'

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}
void solve()
{
	ll n, p, w, d;
	cin >> n >> p >> d >> w;
	var md = p % w;
	ll dCnt = 0;
	ll curd = 0;
	ll cnt = 0;
	while (curd%w != md)
	{
		dCnt++;
		curd = (curd + d) % w;
		++cnt;
		if (cnt == w + 1)
		{
			cout << -1;
			return;
		}
	}
	n -= dCnt;
	p -= dCnt * d;
	if (n < 0 || p < 0)
	{
		cout << -1;
		return;
	}
	var c = w / gcd(d, w);
	var x = (p / (c*d))*c;
	dCnt += x;
	n -= x;
	p = p % (c*d);
	var wCnt = p / w;
	n -= wCnt;
	if (n < 0)
	{
		cout << -1;
	}
	else
	{
		cout << dCnt << " " << wCnt << " " << n;
	}
}
int main()
{
	int t;
	//cin >> t;
	t = 1;
	for (int i = 0; i < t; ++i)
		solve();
}