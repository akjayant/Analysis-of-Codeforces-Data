#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, p, w, d;
ll x, z;

bool calc(ll y)
{
	if ((p - y * d) % w != 0) return false;
	x = (p - y * d) / w;
	z = (n - x - y);
	if (x >= 0 && y >= 0 && z >= 0) return true;
	return false;
}

int main()
{
	cin >> n >> p >> w >> d;
	for (ll y = 0; y <= 100000; y++)
		if (calc(y))
		{
			cout << x << ' ' << y << ' ' << z << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}
