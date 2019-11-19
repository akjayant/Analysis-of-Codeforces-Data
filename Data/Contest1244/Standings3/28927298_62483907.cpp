#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll n, p, w, d;
	cin >> n >> p >> w >> d;

	ll x = -1;
	for (ll i = 0; i < d; i++)
	{
		if ((p - i * w) >= 0 && (p - i * w) % d == 0)
		{
			x = i;
			break;
		}
	}

	if (x == -1)
	{
		cout << -1 << endl;
	}
	else
	{
		ll y = (p - x * w) / d;
		y %= w;
		x = (p - d * y) / w;
		if (x + y <= n)
		{
			cout << x << ' ' << y << ' ' << n - x - y << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
}