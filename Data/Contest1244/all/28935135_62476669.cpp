#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double lf;
typedef pair<int, int> pii;
 
const int N = 111111;
const int M = 666;
const ll md = 1e9 + 7;
 
ll n, m, k, q;
int ans;
ll x, y;

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	ios::sync_with_stdio(false); cout<<setprecision(20);
 
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &x, &y);
	ll t = gcd(m, gcd(x, y));
	m /= t;
	x /= t;
	y /= t;
	if (gcd(x, y) == 1)
	{
		for (ll xx = m / x, d = m % x, yy = 0; yy <= x && xx >= 0;)
		{
			if (d == 0 && xx + yy <= n)
			{
				printf("%I64d %I64d %I64d\n", xx, yy, n - xx - yy);
				ans = 1;
				break;
			}
			yy++;
			d -= y;
			if (d < 0)
			{
				ll tt = (-d - 1) / x + 1;
				d += tt * x;
				xx -= tt;
			}
		}
	}
	if (!ans)
	{
		puts("-1");
	}
	
	return 0;
}