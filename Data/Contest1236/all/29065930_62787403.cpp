#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 1e5+5, mod = 1e9+7;
ll power(ll x, ll y)
{
	if(y == 0) return 1;
	ll temp = power(x, y/2);
	temp *= temp, temp %= mod;
	if(y%2) temp *= x, temp %= mod;
	return temp;
}
int main()
{
	ll x, y;
	cin >> x >> y;
	ll tmp = (power(2, y)-1 + mod)%mod;
	cout << power(tmp, x) << endl;
}