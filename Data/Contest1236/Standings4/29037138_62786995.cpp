#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9 + 7;
ll power(ll x, ll t) {
	ll ret = 1;
	for(; t; t >>= 1, x = x * x % P)
		if(t & 1)
			ret = ret * x % P;
	return ret;
}
int main() {
	ll n, m;
	cin >> n >> m;
	ll tmp = power(2, m) - 1;
	tmp = (tmp + P) % P;
	cout << power(tmp, n) << endl;
	return 0;
}