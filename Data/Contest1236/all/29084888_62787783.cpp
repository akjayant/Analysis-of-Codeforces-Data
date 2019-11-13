#include <iostream>
#include <iomanip>
#include <stack>
#define ll long long
#define ui unsigned int
using namespace std;
const int INF = 1e9;
const ll mod = (1e9) + 7;
ll binpow(ll a, ll b)
{
	if (b == 1)
		return a;
	ll ans = binpow(a, b / 2);
	ans *= ans;
	ans %= mod;
	if (b % 2)
		ans *= a;
	return ans % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	cout << binpow(binpow(2, m) - 1, n);
	return 0;
}