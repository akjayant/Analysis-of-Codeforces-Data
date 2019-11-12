#include <iostream>

using namespace std;

typedef long long ll;
const ll P = 1000000007;
ll mypow(ll a, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n % 2)
		{
			res *= a;
			res %= P;
		}
		n >>= 1;
		a *= a;
		a %= P;
	}
	return res;
}

int main()
{
	ll n, m;
	cin >> n >> m;
	cout << mypow((mypow(2, m) + P - 1) % P, n);
}