#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
const int mod = 1e9 + 7;
ll Pow(ll a, int x) {
	ll res = 1;
	while (x) {
		if (x & 1) (res *= a) %= mod;
		(a *= a) %= mod;
		x >>= 1;
	}
	return res;
}
int main() {
	int n, m;
	cin >> n >> m;
	//if (n > m) return puts("0");
	ll mm = Pow(2, m);
	ll ans = Pow((mm - 1 + mod) % mod, n);
	cout << ans;
}
